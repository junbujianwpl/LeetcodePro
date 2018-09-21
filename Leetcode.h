#ifndef LEETCODE_H
#define LEETCODE_H

#include <bits/stdc++.h>
#include <vector>
#include <map>
#include "common.h"

typedef unsigned int UINT;

using std::vector;
using std::map;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

    static vector<int> twoSumIndexLeet(vector<int>& nums, int target);

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


    /**
     * @brief delSameMoreThanNBetter	better one. convert the issue to a simple del same issue.
     * @param arr                       array
     * @param len                       array len
     * @param max                       the up limitation of the same ele number
     * @return                          run times
     */
    static int delSameMoreThanNBetter(int *arr, int &len,int max);

    static float getMedianOfTwoSortedArr(int *nums1, int len, int *nums2, int len2);


    static  int getHIndexOfPaper(vector<int>& v);


    /**
     * @brief searchMatrix binary search. add binary search postions into stacks and until stack empty
     * @param matrix
     * @param target
     * @return
     */
    static  bool searchMatrix(vector<vector<int> >& matrix, int target);


    static int findKth(vector<int>::const_iterator A,int m,vector<int>::const_iterator B,int n,int k);

    static int binarySearch(vector<int> v,int dst);
    static int binarySearchFromRotate(vector<int> nums, int target);


    vector<vector<int> > permute(vector<int> &nums);


    /**
     * @brief permute recursive make the first element fixed and calc sub array permute
     * @param nums
     * @param start
     * @return
     */
    vector<vector<int> > permute(vector<int> &nums, int start);


    /**
     * @brief numMatchingSubseq get number of matching subseq of words in S
     * @param S         searching in S
     * @param words     search for words
     * @return          searched ele num of words
     */
    int numMatchingSubseq(string S, vector<string>& words);

    /**
     * @brief partitionNearestSumSubArr  partition a array to two sub array,whose sum are nearest
     * @param arr     input arr
     * @return        output subarr
     */
    static vector<vector<int> > partitionNearestSumSubArr(const vector<int>& arr);

    static void nextPermutation(vector<int>& nums) ;

////*****************************************Examinations********************************************////


    /**
     * @brief getPrime         get the idx'th prime from first prime 2
     * @param idx              the index of prime array
     * @return                 the prime
     */
    static UINT getPrime(UINT idx);

    /**
     * @brief getPrimesLessThan       get all primes Less than dst
     * @param dst                     the up limits of prime
     * @return                        the ordered array of primes
     */
    static std::vector<UINT> getPrimesLessThan(UINT dst);


    /**
     * @brief sqrt                 calc square root of dst
     * @param d                    the input
     * @param loss                 the episode
     * @return                     the square root of dst
     */
    static double sqrt(double d,double loss=0.00000001);


    static double cubeRoot(double d,double loss=0.00000001);

    /**
     * @brief getTwoPrimeSumFactor        get all prime pairs whose sum is dst
     * @param sum                         sum val
     * @param withOne                     within 1 or not
     * @return                            all prime pairs
     */
    static std::vector<std::vector<UINT> > getTwoPrimeSumFactor(UINT sum, bool withOne=false);


////*****************************************Miscellaneous********************************************////
    static int findNthDigit(int n);

    static int digitsUntilN(int n);

    static int reverseInteger(int x);

////*****************************************linked list********************************************////
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

};

#endif // LEETCODE_H
