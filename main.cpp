
#include "SortAlgorithmn.h"
#include "common.h"
#include "tests/TestLeetCode.h"
#include "tests/TestSortAlgorithmn.h"
#include "tests/TestDFS.h"

#include "YangHuiTriangle.h"
#include "ComputerBase.h"
#include <vector>
using std::vector;
#include "Combination.h"
#include "BallWeigher.h"
#include "tests/TestTree.h"
#include "tests/TestBFS.h"
#include "tests/TestAtomic.h"

int main(int argc,char** argv){

    TestLeetCode::oddEvenListTest();
    return 0;
    TestAtomic::testAtomicArrayInThreads();
    return 0;

    TestAtomic::testAtomicInThreads();
    return 0;


    TestBFS::testDist();
    return 0;

    TestLeetCode::mergeSortedListTest();
    return 0;
    TestLeetCode::commonPrefixTest();
    return 0;

    TestLeetCode::nextpermutationTest();
    return 0;

    TestLeetCode::addTwoLinkListTest();
    return 0;
    TestLeetCode::twoSumTestLeet();
    return 0;
    TestLeetCode::binSearchRotateTest();
    return 0;
    TestLeetCode::binSearchTest();
    return 0;
    TestLeetCode::findKthTest();
    return 0;

    TestTree::postorderTest();
    return 0;

    ComputerBase::printIntBitStr(128);
    ComputerBase::printIntBitStr(-128);
    ComputerBase::printIntBitStr(std::numeric_limits<int>::min());
    ComputerBase::printIntBitStr(std::numeric_limits<int>::max());
    std::cout<<std::numeric_limits<int>::max()-std::numeric_limits<int>::max()/10*10<<std::endl;
    std::cout<<std::numeric_limits<int>::min()-std::numeric_limits<int>::min()/10*10<<std::endl;
    return 0;
    TestLeetCode::reverseIntegerTest();
    return 0;
    TestLeetCode::shuffleTest();
    return 0;
    TestLeetCode::rightShiftTest();
    TestLeetCode::reverseTest();

//    Combination com(12);
//    vector<vector<vector<int> > > ttt=com.getNthCombinationGroup(12,3);
//    for(int i=0;i<ttt.size();++i){
//        print_2d_arr(ttt[i],ttt.at(0).size(),ttt.at(0).at(0).size());
//    }
//    return 1;
//    vector<vector<int> > r=com.getNthCombination(ttt.size());
//    vector<vector<int> > sel=Combination(r.size()).getNthCombination(2);
//    BallWeigher ballW;
//    for(int i=0;i<3 && i<sel.size();++i){
//        ballW.compare(r.at(sel.at(i).at(0)),r.at(sel.at(i).at(1)));
//    }
//    std::cout<<ballW.getBallsString().c_str()<<endl;
//    return 1;
//    for(int i=1;i<3;++i){
//    vector<vector<int> > result = com.getNthCombination(i);
//    print_2d_arr(result,result.size(),result.at(0).size());
//    }
//    return 1;


//    std::cout<<"hello world"<<std::endl;
//    int arr[]={1,2,9,2,4,5,222,29,20};
//    print_arr(arr,ARR_SIZE(arr));

//    vector<int> v({1,2,9,2,4,5,222,29,20});

//    SortAlgorithmn::qsort(v,v.begin(),v.end());
//    print_arr(v,v.size());
//    print_arr(arr,ARR_SIZE(arr));

//    TestLeetCode::twoSumTest();
//    TestLeetCode::threeSumTest();

//    TestLeetCode::twoSumIndexTest();

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

//    TestLeetCode::digitsUntilNTest();
//    TestLeetCode::nThDigitTest();

//    TestDFS::testGetLayout();

//    TestLeetCode::partionNearestSubArray();

    YangHuiTriangle yh(15);
    yh.printTriangle();

    std::vector<std::vector<uint32_t> > vec2d=yh.getTriangle2D();
    std::cout<<"lines"<<vec2d.size()<<std::endl;
    for(int i=0;i<vec2d.size();++i){
//        std::cout<<" cur Line ele num"<<vec2d.at(i).size()<<std::endl;
        for(int j=0;j<vec2d.at(i).size();++j){
            std::cout<<vec2d[i][j]<<" ";
        }
        std::cout<<std::endl;
    }



}
