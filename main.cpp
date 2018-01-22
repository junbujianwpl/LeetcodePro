
#include "SortAlgorithmn.h"
#include "common.h"
#include "tests/TestLeetCode.h"
#include "tests/TestSortAlgorithmn.h"
#include <vector>
using std::vector;

int main(int argc,char** argv){

    std::cout<<"hello world"<<std::endl;
    int arr[]={1,2,9,2,4,5,222,29,20};
    print_arr(arr,ARR_SIZE(arr));

    vector<int> v({1,2,9,2,4,5,222,29,20});

    SortAlgorithmn::qsort(v,v.begin(),v.end());
    print_arr(v,v.size());
//    print_arr(arr,ARR_SIZE(arr));

    TestLeetCode::twoSumTest();
    TestLeetCode::threeSumTest();

    TestLeetCode::twoSumIndexTest();

//    TestLeetCode::delSameInSortedArrTest();
//    TestLeetCode::delSameInSortedArrMaxTest();
//    TestLeetCode::delSameInSortedArrMaxBetterTest();
//    TestLeetCode::getPrimeTest();
//    TestLeetCode::getPrimeSumFactorTest();
//    TestLeetCode::sqrtTest();
//    TestLeetCode::cubeRootTest();
//    TestLeetCode::getTwoSortArrMediaTest();

//    TestSortAlgorithmn::qsortTest();

//    TestLeetCode::search2DMatrixTest();

    TestLeetCode::digitsUntilNTest();
    TestLeetCode::nThDigitTest();

}
