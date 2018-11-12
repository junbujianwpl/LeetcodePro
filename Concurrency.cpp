#include "Concurrency.h"
#include "common.h"

namespace _concurrency {
    static ostringstream logs;
    static mutex mut;
}

template<class T>
int Concurrency<T>::work()
{
    static atomic<int> id(0);
    int myid=id++;
    int idx;
    atomic<int> count(0);		//<if not atomic ++ op may be optimized after oss<<
    ostringstream oss;
    while((idx=m_aiCurJobIdx__++)<m_tasks__.size()){
        ++count;
        m_results__[idx]=m_tasks__[idx]();
//        oss<<"thread id:"<<myid<<" done job "<<idx<<endl;
    }
    oss<<"-------"<<myid<<" done "<<count.load(memory_order_acquire)<<" jobs"<<endl<<endl;
    lock_guard<mutex> lock(_concurrency::mut);		///<RAII
    _concurrency::logs<<oss.str();
    return myid;
}

template<class T>
int Concurrency<T>::payload()
{
    static atomic<int> sai(0);

    int ret=sai++;
    int sleepTime=random()%1000;
    cout<<"sleep "<<sleepTime<<"ms,return val:"<<ret<<endl;
    this_thread::sleep_for(chrono::milliseconds(sleepTime));
    return ret;
}

template<class T>
Concurrency<T>::Concurrency(vector<function<T> > &vt, vector<int> &vr, int num):m_tasks__(vt),m_results__(vr),m_aiCurJobIdx__(0)
{
    vector<thread> vth;
    for(int i=0;i<num;++i){
        vth.emplace_back(thread(&Concurrency::work,this));
    }

    for(auto &t:vth){
        t.join();
    }

}

template<class T>
void Concurrency<T>::test()
{
    int nJobNum=100,nThreadNum=5;
    vector<function<T> > jobs(nJobNum,Concurrency::payload);
    vector<int> results(nJobNum,-1);
    Concurrency(jobs,results,nThreadNum);

    print_arr_raw(results,results.size());
    cout<<endl;
    cout<<_concurrency::logs.str().c_str()<<endl;

}

