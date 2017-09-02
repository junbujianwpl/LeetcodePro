#include "Leetcode.h"

#include "SortAlgorithmn.h"
#include <iostream>
#include <QObject>

Leetcode::Leetcode()
{

}

std::vector<std::vector<int> > Leetcode::twoSum(std::vector<int> arr, int dst, int *time)
{
    //return all pairs whos sum equals dst.
    if(NULL != time){
        *time=0;
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

    if(NULL != time){
        *time=runtimes;
    }
    std::cout<<"twosum runtimes:"<<runtimes<<",len of arr:"<<arr.size()<<std::endl;
    return result;

}

std::vector<std::vector<int> > Leetcode::threeSum(std::vector<int> arr, int dst, int *time)
{
    //return all three sum pairs whos sum equals dst.
    if(NULL != time){
        *time=0;
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

    if(NULL != time){
        *time=runtimes;
    }

    return result;
}
