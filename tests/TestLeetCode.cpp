#include "TestLeetCode.h"
#include <QObject>


static std::vector<std::vector<int> >result;
static int arr[]={2,4,9,8,99,88,22,10,5,7,1};

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
