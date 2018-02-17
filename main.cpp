
#include "SortAlgorithmn.h"
#include "common.h"
#include "tests/TestLeetCode.h"
#include "tests/TestSortAlgorithmn.h"
#include "Combination.h"
#include "BallWeigher.h"

int main(int argc,char** argv){

    Combination com(12);
    vector<vector<vector<int> > > ttt=com.getNthCombinationGroup(12,3);
//    for(int i=0;i<ttt.size();++i){
//        print_2d_arr(ttt[i],ttt.at(0).size(),ttt.at(0).at(0).size());
//    }
//    return 1;
    vector<vector<int> > r=com.getNthCombination(ttt.size());
    vector<vector<int> > sel=Combination(r.size()).getNthCombination(2);
    BallWeigher ballW;
    for(int i=0;i<3 && i<sel.size();++i){
        ballW.compare(r.at(sel.at(i).at(0)),r.at(sel.at(i).at(1)));
    }
    std::cout<<ballW.getBallsString().c_str()<<endl;
    return 1;
    for(int i=1;i<3;++i){
    vector<vector<int> > result = com.getNthCombination(i);
    print_2d_arr(result,result.size(),result.at(0).size());
    }
    return 1;


    std::cout<<"hello world"<<std::endl;
    int arr[]={1,2,9,2,4,5,222,29,20};
    print_arr(arr,ARR_SIZE(arr));
    SortAlgorithmn::heapSort(arr,ARR_SIZE(arr));
    print_arr(arr,ARR_SIZE(arr));

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
