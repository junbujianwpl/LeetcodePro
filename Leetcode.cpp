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
