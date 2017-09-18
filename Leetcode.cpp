#include "Leetcode.h"

#include "SortAlgorithmn.h"
#include <iostream>
#include <QObject>

Leetcode::Leetcode()
{

}

std::vector<std::vector<int> > Leetcode::twoSum(std::vector<int> arr, int dst, int *times)
{
    //return all pairs whos sum equals dst. O(n)=n*logn;
    if(NULL != times){
        *times=0;
    }
    std::vector<std::vector<int> > result;
    if(arr.size()<2)
        return result;

    int runtimes = SortAlgorithmn::quickSort(&arr.at(0),arr.size());

    std::cout<<"qsort runtimes:"<<runtimes<<",len of arr:"<<arr.size()<<std::endl;
    print_arr(arr,arr.size());
    int i=0;
    int j=arr.size()-1;
    while(i<j){
        int sum=arr[i]+arr[j];
        if(sum>dst){
            --j;
        }else if(sum<dst){
            ++i;
        }else{
            std::vector<int> t;
            t.push_back(arr.at(i++));       //avoid repeating use i add to same j
            t.push_back(arr.at(j));
            result.push_back(t);
        }
        ++runtimes;
    }

    if(NULL != times){
        *times=runtimes;
    }
    std::cout<<"twosum runtimes:"<<runtimes<<",len of arr:"<<arr.size()<<",dst:"<<dst<<std::endl;
    return result;

}

std::vector<std::vector<int> > Leetcode::twoSumIndex(std::vector<int> arr, int dst, int *times)
{
    //return all three sum pairs' index whos sum equals dst. O(n)=n*n;

    ///<use a map to save the ele:index pair. use twosum and return the pairs' origin index. so the elements must be unique.

    std::vector<std::vector<int> > result;
    if(NULL != times){
        *times=0;
    }
    if(arr.size()<2){
        return result;
    }

    std::map<int,int> index;
    for(int i=0;i<arr.size();i++) {
        index.insert(std::pair<int,int>(arr.at(i),i));
    }

    std::vector<std::vector<int> > vals=twoSum(arr,dst,times);
    foreach (std::vector<int> vv, vals) {
    std::vector<int> t;
        foreach (int v, vv) {
            t.push_back((*index.find(v)).second);
        }
        result.push_back(t);
    }

    return result;
}

std::vector<std::vector<int> > Leetcode::threeSum(std::vector<int> arr, int dst, int *times)
{
    //return all three sum pairs whos sum equals dst. O(n)=n*n;
    if(NULL != times){
        *times=0;
    }

    std::vector<std::vector<int> > result;
    if(arr.size()<3){
        return result;
    }

    int runtimes=0;
    print_arr(arr,arr.size());
    runtimes+=SortAlgorithmn::quickSort(&*arr.begin(),arr.size());
    int tmp=0;

    for(int i=0;i<arr.size()-2;i++){
       std::vector<std::vector<int> > vv=twoSum(std::vector<int>(arr.begin()+i,arr.end()),dst-arr.at(i),&tmp);
       foreach (std::vector<int> v, vv) {
          v.push_back(arr.at(i));
          result.push_back(v);
       }
       runtimes+=tmp;
    }

    if(NULL != times){
        *times=runtimes;
    }

    return result;
}

int Leetcode::delSame(int *arr, int& len)
{
    //del same element from a sorted arr
    int times=0;

    int j=0;
    for(int i=0;i<len;i++){
        if(arr[j]!=arr[i]){
            arr[++j]=arr[i];
        }
        ++times;
    }

    len=++j;
    return times;
}

int Leetcode::delSameMoreThanN(int *arr, int &len, int max)
{
    //del same ele when the number of same elements exceed max
    int times=0;

    int count=0;
    int j=0;
    for(int i=0;i<len;i++){
        if(arr[j]==arr[i]){
            ++count;
            if(count<=max){
                arr[++j]=arr[i];
            }
        }else{
            count=0;
            arr[++j]=arr[i];
        }
        times++;
    }
    len=++j;

    return times;

}

int Leetcode::delSameMoreThanNBetter(int *arr, int &len, int max)
{
    int times=0;
    int j=max;
    for(int i=max;i<len;i++){
        if(arr[j-max]!=arr[i]){
            arr[j++]=arr[i];
        }
        ++times;
    }
    len=j;
    return times;
}

UINT Leetcode::getPrime(UINT idx)
{
    static std::vector<UINT> primes({2,3});

    if(idx<primes.size()){
        return primes.at(idx);
    }

    UINT div=2;
    for(UINT dst=*primes.rbegin()+1;;dst++){
        for(div=2;div<sqrt(dst)+1;div++){
            if(dst%div==0){
                break;
            }
        }
        if(div>sqrt(dst)){
            primes.push_back(dst);
            return dst;
        }
    }
}

std::vector<UINT> Leetcode::getPrimesLessThan(UINT dst)
{
    std::vector<UINT> result;
    UINT prime=0;
    for(UINT i=0;(prime=getPrime(i))<dst;i++){
        result.push_back(prime);
    }
    return result;
}

double Leetcode::sqrt(double d, double loss)
{
    //newton formula.the curve y=f(x).we use the tangent line to simulate its root in some condition.
    //. f(x0)+f'(x0)(x-x0)=y. make y=0. use the line root to simulate root of the curve f(x)=0. get the root
    //and mark it as x1. the we use tangent line at x1 and to get the root and mark it as x2. iter until we
    //get the xn whose loss isn't beyond our expection. f(x0)+f'(x0)(x-x0)=0, x1=x0-f(x0)/f'(x0).
    //so, if we get N as input, we want N^(0.5)=x. so x^2-N=0. then our f(x)=x^2-N. f'(x)=2x.
    //so, x1=x0-(x0^2-N)/2x0=0.5x0+0.5N/x0. make x0=1. f(x0)=1. x1=1-1/2=0.5. x2=x1-(x1^2-N)/2x1
    double x=1.0;
    do{
        x=0.5*x+0.5*d/x;
    }while(fabs(x*x-d)>loss);

    return x;
}

std::vector<std::vector<UINT> > Leetcode::getTwoPrimeSumFactor(UINT sum, bool withOne)
{
    std::vector<std::vector<UINT> > result;
    std::vector<UINT> primes=getPrimesLessThan(sum);
    if(withOne){
        primes.insert(primes.begin(),1);
    }

    print_arr(primes,primes.size());

    UINT i=0;
    UINT j=primes.size()-1;

    while(i<j){
        while(i<j && primes.at(i)+primes.at(j)<sum){
            ++i;
        }
        while(i<j && primes.at(i)+primes.at(j)>sum){
            --j;
        }
        if(primes.at(i)+primes.at(j)==sum){
            std::vector<UINT> v({primes.at(i++),primes.at(j)});
            result.push_back(v);
        }
    }
    return result;
}

