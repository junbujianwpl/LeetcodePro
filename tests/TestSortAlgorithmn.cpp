#include "TestSortAlgorithmn.h"

TestSortAlgorithmn::TestSortAlgorithmn()
{

}

void TestSortAlgorithmn::testQuickSort()
{
    int arr[]={2,1,4,9,99,33,22,55,21,42,90};
    print_arr(arr,ARR_SIZE(arr));
    SortAlgorithmn::quickSort(arr,ARR_SIZE(arr));
    print_arr(arr,ARR_SIZE(arr));
}

void TestSortAlgorithmn::testHeapSort()
{
    int arr[]={2,1,4,9,99,33,22,55,21,42,90};
    print_arr(arr,ARR_SIZE(arr));
    SortAlgorithmn::heapSort(arr,ARR_SIZE(arr));
    print_arr(arr,ARR_SIZE(arr));

}


//QTEST_MAIN(TestSortAlgorithmn)
