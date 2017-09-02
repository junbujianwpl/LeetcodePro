#ifndef LEETCODE_H
#define LEETCODE_H

#include <vector>
#include <map>
#include "common.h"

class Leetcode
{
public:
    Leetcode();
    
    static std::vector<std::vector<int> > twoSum(std::vector<int> arr,int dst, int *time=NULL);

    static std::vector<std::vector<int> > twoSumIndex(std::vector<int> arr,int dst, int *time=NULL);

    static std::vector<std::vector<int> > threeSum(std::vector<int> arr,int dst, int *time=NULL);
};

#endif // LEETCODE_H
