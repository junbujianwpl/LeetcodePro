#ifndef SORTALGORITHMN_H
#define SORTALGORITHMN_H


#include <vector>
#include <stack>
using std::stack;
using std::vector;

class SortAlgorithmn
{
public:
    SortAlgorithmn();

    static int quickSort(int *nums,int count);

    static int quickSort(vector<int>& v);

    static int  heapSort(int *arr,int len);

private:
    static int  adjustHeap(int *arr,int start,int max);
};

#endif // SORTALGORITHMN_H
