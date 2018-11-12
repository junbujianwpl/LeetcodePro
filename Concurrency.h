#ifndef CONCURRENCY_H
#define CONCURRENCY_H

#include <bits/stdc++.h>
using namespace std;

template<class T>
class Concurrency
{
    vector<function<T>> &m_tasks__;		///<reference to tasks vector
    vector<int> &m_results__;			///<reference to result vector

    atomic<int> m_aiCurJobIdx__;

    int work();

    static int payload();
public:
    Concurrency(vector<function<T> > &vt,vector<int> &vr,int num);

    static void test();
};

#endif // CONCURRENCY_H
