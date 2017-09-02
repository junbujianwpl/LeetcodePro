#ifndef LEETCODE_H
#define LEETCODE_H

#include <vector>
#include <map>
#include "common.h"

class Leetcode
{
public:
    Leetcode();
    
    /**
     * @brief twoSum return all pairs whose sum is dst
     * @param arr    input array
     * @param dst    dst val
     * @param times  run times
     * @return       vector of all pairs
     */
    static std::vector<std::vector<int> > twoSum(std::vector<int> arr, int dst, int *times=NULL);

    /**
     * @brief twoSumIndex     return all index pairs of two element whose sumary is dst
     * @param arr	      input array
     * @param dst	      dst val
     * @param times	      run times
     * @return 		      vector of pair's index
     */
    static std::vector<std::vector<int> > twoSumIndex(std::vector<int> arr, int dst, int *times=NULL);

    /**
     * @brief threeSum        return all 3d pairs whose sum is dst
     * @param arr	      input array
     * @param dst	      dst val
     * @param times	      run times
     * @return 		      vector of pair's index
     */
    static std::vector<std::vector<int> > threeSum(std::vector<int> arr, int dst, int *times=NULL);





};

#endif // LEETCODE_H
