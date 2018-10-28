#ifndef ATOMICLAB_H
#define ATOMICLAB_H

#include<bits/stdc++.h>
using namespace std;

template<class T>
class Array
{
//    vector<atomic<T> > m_vec__;
//    vector<T>    m_vec__;

//    atomic<T>* m_pData__;
//    unsigned int m_uiSize__;
//    unsigned int m_uiLen__;

public:
//    Array(unsigned int len){
//        m_vec__.assign(len,0);
//    }

//    T& operator[](unsigned int idx){
//       return m_vec__[0];
//    }

//    void add(unsigned int idx,T t){
//        T old=m_vec__[idx].load()+t;
//        m_vec__[idx].store(old);
//    }
//    void set(unsigned int idx,T t){
//        m_vec__[idx].store(t);
//        atomic<T> rel(0);
//        int ret=rel.load(256);
//        static int si=256;
//        rel.store(si++);
//    }

//    int get(unsigned int idx){
//        return m_vec__[idx].load();
//    }

};


class AtomicLab
{
    atomic<long long> m_allData__;
    long long m_llData__;
public:
    AtomicLab();

    void addSafe(int n);
    void addNoSafe(int n);

    void print();

};

#endif // ATOMICLAB_H
