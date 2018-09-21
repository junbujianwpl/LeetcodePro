#include "TestLeetCode.h"
#include <QObject>
#include "SortAlgorithmn.h"
#include "Shuffle.h"

using namespace std;


static std::vector<std::vector<int> >result;
static int arr[]={2,1,7,9,22,5,5,3,4,6,4,9,8,99,88,22,10,5,7,1,7,6,4,4,3,2,4,3,6,8,7,9,7,8};

static void print_2d_vec(std::vector<std::vector<int> > in){

    foreach (std::vector<int> v, in) {
        foreach (int i, v) {
           std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }
}

template<typename T>
static void print_2d_vec_temp(std::vector<std::vector<T> > in){

    foreach (std::vector<T> v, in) {
        foreach (T i, v) {
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

void TestLeetCode::getPrimeTest()
{
    for(int i=0;i<50;i++){
        std::cout<<Leetcode::getPrime(i)<<" ";
    }
    std::cout<<std::endl;
}

void TestLeetCode::getPrimeSumFactorTest()
{
    std::vector<UINT> in({20,30,40,50,33,44,68,99});
    for(int i=0;i<in.size();i++){
        std::vector<std::vector<UINT> > vs=Leetcode::getTwoPrimeSumFactor(in.at(i));
        std::cout<<in.at(i)<<": ";
        print_2d_vec_temp<UINT>(vs);
        std::cout<<std::endl;
    }

}

void TestLeetCode::sqrtTest()
{
    double arr[]={2,3,4,9,16,19,22,25};
    for(int i=0;i<ARR_SIZE(arr);i++){
        std::cout<<arr[i]<<":"<<Leetcode::sqrt(arr[i])<<std::endl;
    }
}

void TestLeetCode::cubeRootTest()
{
    double arr[]={2,3,9,8,27,16,99,100,1000};
    for(int i=0;i<ARR_SIZE(arr);i++){
        std::cout<<arr[i]<<":"<<Leetcode::cubeRoot(arr[i])<<std::endl;
    }
}

void TestLeetCode::getTwoSortArrMediaTest()
{
    int arr[]={2};
    int arr2[]={};

    SortAlgorithmn::quickSort(arr,ARR_SIZE(arr));
    SortAlgorithmn::quickSort(arr2,ARR_SIZE(arr2));

    float media = Leetcode::getMedianOfTwoSortedArr(arr,ARR_SIZE(arr),arr2,ARR_SIZE(arr2));

    print_arr(arr,ARR_SIZE(arr));
    print_arr(arr2,ARR_SIZE(arr2));

    std::cout<<"media is "<<media<<std::endl;






}

bool TestLeetCode::search2DMatrixTest()
{
    vector<vector<int> > v({
                               {1,4,7,11,15},
                               {2,5,8,12,19},
                               {3,6,9,16,22},
                               {10,13,14,17,24},
                               {18,21,23,26,30}
                           });

    print_2d_vec(v);
    for(int i=0;i<v.size();i++)
        for(int j=0;j<v.at(i).size();j++)
        std::cout<<Leetcode::searchMatrix(v,v[i][j])<<std::endl;

}

int TestLeetCode::digitsUntilNTest()
{
    int in[]={1,4,10,12,13,14,20};
    for(int i=0;i<ARR_SIZE(in);i++){
        int num=in[i];
        std::cout<<num<<","<<Leetcode::digitsUntilN(num)<<std::endl;
    }
    return 1;

}

int TestLeetCode::nThDigitTest()
{
    string s;
    for(int i=1;i<20;i++){
        char sz[10];
        sprintf(sz,"%d",i);
        s+=sz;
    }
    for(unsigned int i=0;i<s.size();i++){
        std::cout<<i+1<<":"<<s.at(i)<<",";
    }
    std::cout<<std::endl;
    int in[]={1,4,10,12,13,14,20};
    for(unsigned int i=0;i<ARR_SIZE(in);i++){
        int num=in[i];
        std::cout<<num<<","<<Leetcode::findNthDigit(num)<<std::endl;
    }
    return 1;


}

void TestLeetCode::reverseTest()
{
    vector<int> vec(10,0);
    for(unsigned int i=0;i<vec.size();++i){
        vec[i]=i+1;
    }

    Shuffle<int>::reverse(vec.begin(),vec.end());
    print_arr(vec,vec.size());


}

void TestLeetCode::rightShiftTest()
{
    vector<int> vec(10,0);
    for(unsigned int i=0;i<vec.size();++i){
        vec[i]=i+1;
    }
    Shuffle<int>::rightCycleMove(vec.begin(),vec.end(),22);
    print_arr(vec,vec.size());

}

void TestLeetCode::shuffleTest()
{
    for(int k=2;k<40;k+=2){
        vector<int> vec(k,0);
        for(unsigned int i=0;i<vec.size();++i){
            vec[i]=i+1;
        }
        Shuffle<int> shuffle(vec);
        std::cout<<shuffle.shuffle()<<std::endl;
        vec=shuffle.getData();
        print_arr(vec,vec.size());
    }

}

void TestLeetCode::partionNearestSubArray()
{
    vector<int> v;
    v.assign(arr,&arr[1]);
//    v.assign(arr,&arr[5]);
//    v.assign(arr,&arr[ARR_SIZE(arr)-1]);
    vector<vector<int> > result=Leetcode::partitionNearestSumSubArr(v);
    print_2d_vec(result);


}

void TestLeetCode::reverseIntegerTest()
{
    int i=123;
    vector<int> vecInput({1,0,12,123456,-123456789,std::numeric_limits<int>::max(),std::numeric_limits<int>::min(),1534236469});
    for(auto i:vecInput){
        int x=Leetcode::reverseInteger(i);
        std::cout<<i<<" "<<x<<std::endl;
    }
}

void TestLeetCode::findKthTest()
{
    vector<int> A({1,2,3,5,6,7}) ;
    vector<int> B({1,3,5,7,9,20,48,100}) ;
    print_arr(A,A.size());
    print_arr(B,B.size());
    for(uint i=1;i<=A.size()+B.size();++i){
        std::cout<<i<<"  "<<Leetcode::findKth(A.begin(),A.size(),B.begin(),B.size(),i)<<std::endl;
    }
}

void TestLeetCode::binSearchTest()
{
    vector<int> A({1,2,3,4,5,6,7,7,9,20,100});
    print_arr(A,A.size());
    for(auto i:A){
        std::cout<<i<<" "<<Leetcode::binarySearch(A,i)<<std::endl;
    }
}

void TestLeetCode::binSearchRotateTest()
{
    vector<int> A({5,6,7,8,9,20,100,200,201,202,203,1,2,3,4});
    print_arr(A,A.size());
    for(auto i:A){
        std::cout<<i<<" "<<Leetcode::binarySearchFromRotate(A,i)<<std::endl;
    }

}

void TestLeetCode::twoSumTestLeet()
{
//    vector<int> v({1,2,3,4,56,56,565,4});
//    vector<int> v({3,2,4,1,2,3,4,5,6,99,88,77});
    vector<int> v({230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789});
//    int dst=542;
//    SortAlgorithmn::qsort(v,v.begin(),v.end());
    int dst=100;
    for(auto i: Leetcode::twoSumIndexLeet(v,dst)){
        std::cout<<i<<std::endl;
    }

}

void TestLeetCode::addTwoLinkListTest()
{
    vector<ListNode> v1({ListNode(1),ListNode(1),ListNode(8),ListNode(9),});
    vector<ListNode> v2({ListNode(4),ListNode(5),ListNode(2),ListNode(9),});

    vector<vector<ListNode> > vv({v1,v2});
    for(int i=0;i<vv.size();++i ){
        for(int j=0;j<vv[i].size()-1;++j){
            vv[i][j].next=&vv[i][j+1];
        }
    }
    ListNode *node=Leetcode::addTwoNumbers(&vv[0][0],&vv[1][0]);
    while(node){
        std::cout<<node->val<<std::endl;
        node=node->next;
    }
}

void TestLeetCode::nextpermutationTest()
{
    vector<int> v({1,2,4,5,6,7,6,5,4});
//    vector<int> v({1,1,5});
//    vector<int> v({3,2,1});
    print_arr(v,v.size());
    Leetcode::nextPermutation(v);
    print_arr(v,v.size());

}
