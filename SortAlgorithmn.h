#ifndef SORTALGORITHMN_H
#define SORTALGORITHMN_H


class SortAlgorithmn
{
public:
    SortAlgorithmn();

    static void quickSort(int *nums,int count);

    static int  heapSort(int *arr,int len);

private:
    static int  adjustHeap(int *arr,int start,int max);
};

#endif // SORTALGORITHMN_H
