#ifndef LEETCODE_H
#define LEETCODE_H

#include <vector>
#include <map>
#include "common.h"

class Leetcode
{
public:
    Leetcode();

////*****************************************ARRAY********************************************////

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



    /**
     * @brief delSame      del same ele in a sorted arr
     * @param arr		   sorted array
     * @param len		   array len,also a output,as the output arr len.
     * @return 			   run times
     */
    static int delSame(int *arr, int &len);


    /**
     * @brief delSameMoreThanN		del redudant ele when nums exceed max
     * @param arr				    array
     * @param len					array len
     * @param max					the max of duplicate elements
     * @return 					    run times
     */
    static int delSameMoreThanN(int *arr, int &len,int max);


};

#endif // LEETCODE_H
