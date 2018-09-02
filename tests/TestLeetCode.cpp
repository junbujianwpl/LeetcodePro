#include "TestLeetCode.h"
#include <QObject>
#include "SortAlgorithmn.h"
#include "Shuffle.h"


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
    for(int i=0;i<s.size();i++){
        std::cout<<i+1<<":"<<s.at(i)<<",";
    }
    std::cout<<std::endl;
    int in[]={1,4,10,12,13,14,20};
    for(int i=0;i<ARR_SIZE(in);i++){
        int num=in[i];
        std::cout<<num<<","<<Leetcode::findNthDigit(num)<<std::endl;
    }
    return 1;


}

void TestLeetCode::reverseTest()
{
    vector<int> vec(10,0);
    for(int i=0;i<vec.size();++i){
        vec[i]=i+1;
    }

    Shuffle::reverse<int>(vec.begin(),vec.end());
    print_arr(vec,vec.size());


}
