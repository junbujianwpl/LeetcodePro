#include "TestLeetCode.h"
#include <QObject>
#include "SortAlgorithmn.h"


static std::vector<std::vector<int> >result;
static int arr[]={2,1,7,9,22,5,5,3,4,6,4,9,8,99,88,22,10,5,7,1,7,6,4,4,3,2,4,3,6,8,7,9,7,8};

static print_2d_vec(std::vector<std::vector<int> > in){

    foreach (std::vector<int> v, in) {
        foreach (int i, v) {
           std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }
}

TestLeetCode::TestLeetCode()
{

}

void TestLeetCode::twoSumTest()
{
    result = Leetcode::twoSum(std::vector<int>(&arr[0],&arr[ARR_SIZE(arr)]),12);
    print_arr(&result.at(0),result.size());

    print_2d_vec(result);
}

void TestLeetCode::twoSumIndexTest()
{
    result=Leetcode::twoSumIndex(std::vector<int>(&arr[0],&arr[ARR_SIZE(arr)]),12);

    print_2d_vec(result);
}

void TestLeetCode::threeSumTest()
{
    int times=0;
    std::vector<int> in(&arr[0],&arr[ARR_SIZE(arr)]);
    print_arr(in,in.size());
    result = Leetcode::threeSum(in,15,&times);

    std::cout<<" three sum runtimes:"<<times<<std::endl;
    print_arr(in,in.size());
    print_2d_vec(result);

}

void TestLeetCode::delSameInSortedArrTest()
{
    int len=ARR_SIZE(arr);
    SortAlgorithmn::quickSort(arr,ARR_SIZE(arr));
    int times=Leetcode::delSame(arr,len);
    print_arr(arr,len);

}

void TestLeetCode::delSameInSortedArrMaxTest()
{
    int len=ARR_SIZE(arr);
    SortAlgorithmn::quickSort(arr,ARR_SIZE(arr));
    print_arr(arr,len);
    int times=Leetcode::delSameMoreThanN(arr,len,1);
    print_arr(arr,len);
}

void TestLeetCode::delSameInSortedArrMaxBetterTest()
{
    int len=ARR_SIZE(arr);
    SortAlgorithmn::quickSort(arr,ARR_SIZE(arr));
    print_arr(arr,len);
    int times=Leetcode::delSameMoreThanNBetter(arr,len,2);
    print_arr(arr,len);
}
