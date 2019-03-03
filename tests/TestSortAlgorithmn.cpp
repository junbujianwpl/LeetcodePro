#include "TestSortAlgorithmn.h"

#include <vector>
using std::vector;
TestSortAlgorithmn::TestSortAlgorithmn()
{

}

void TestSortAlgorithmn::qsortTest()
{
    vector<int> v({1,3,4,2,999,2,8,3,6,7,22,44,22,1,3245,5654,232,65,24332,34234,150});
//    SortAlgorithmn::quickSort(v);
    SortAlgorithmn::qsort(v,v.begin(),v.end());
    print_arr(v,v.size());

}

void TestSortAlgorithmn::testQuickSortIterator()
{
    vector<int> v({-1,0,1,2,-1,-4});
//    vector<int> v({1,2,3,0,5,4,6});
    SortAlgorithmn::quickSort(v.begin(),v.end());
    print_arr(v,v.size());
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
