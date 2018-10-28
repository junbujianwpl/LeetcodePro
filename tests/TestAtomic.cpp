#include "TestAtomic.h"
#include "common.h"
#include "AtomicLab.h"

AtomicLab lab;
//Array<int>    arr(100);

void plusSafe(int i){
    auto start=std::chrono::system_clock::now();
    for(int j=0;j<i;++j)
    lab.addSafe(1);
    auto end=std::chrono::system_clock::now();
    std::chrono::duration<double> used=end-start;
    cout<<"time used"<<used.count()<<endl;
}

void plusNoSafe(int i){
    auto start=std::chrono::system_clock::now();
    for(int j=0;j<i;++j)
    lab.addNoSafe(1);
    auto end=std::chrono::system_clock::now();
    std::chrono::duration<double> used=end-start;
    cout<<"time used"<<used.count()<<endl;
}

void plusArraySafe(int i,int j){
    auto start=std::chrono::system_clock::now();
    for(int j=0;j<i;++j)
//    arr.add(i,1);
    auto end=std::chrono::system_clock::now();
//    std::chrono::duration<double> used=end-start;
//    cout<<"time used"<<used.count()<<endl;
}

TestAtomic::TestAtomic()
{

}

void TestAtomic::testAtomicInThreads()
{
//    vector<thread> v(100,thread(plusNoSafe,1));
//    for(auto i:v){
//        i.join();
//    }
    auto start=std::chrono::system_clock::now();
    unsigned int time=1000000;
    thread t1(plusNoSafe,time);
    thread t2(plusNoSafe,time);
    thread t3(plusSafe,time);
    thread t4(plusSafe,time);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    auto end=std::chrono::system_clock::now();
    std::chrono::duration<double> used=end-start;
//    cout<<"time used"<<used.count()<<endl;

    lab.print();
}

void TestAtomic::testAtomicArrayInThreads()
{
    auto start=std::chrono::system_clock::now();
    unsigned int time=1000000;
    thread t1(plusArraySafe,0,time);
    thread t2(plusArraySafe,0,time);
    thread t3(plusArraySafe,0,time);
    thread t4(plusArraySafe,0,time);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    auto end=std::chrono::system_clock::now();
    std::chrono::duration<double> used=end-start;
//    cout<<"time used"<<used.count()<<endl;
//    cout<<arr.get(0)<<endl;

//    lab.print();

}
