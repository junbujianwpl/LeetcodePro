#ifndef COMMON_H
#define COMMON_H


#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


int print_list_node(ListNode* head);

ListNode* make_list(vector<int> v);

#define ARR_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))


#define print_arr(arr,len) \
    std::cout<<len<<":num "; \
    for(unsigned int iix=0;iix<len;iix++) \
    std::cout<<arr[iix]<<" ";            \
    std::cout<<std::endl;           \

#define print_arr_raw(arr,len) \
    for(int iix=0;iix<len;iix++) \
    std::cout<<arr[iix]<<" ";            \
    std::cout<<std::endl;           \

#define print_2d_arr_raw(arr,row,col) \
    for(int tix=0;tix<row;++tix){  \
       print_arr_raw(arr[tix],col)  }

#define print_2d_arr(arr,row,col) \
    for(int tix=0;tix<row;++tix){  \
       std::cout<<tix<<std::endl;   \
       print_arr(arr[tix],col)  }

#define print_2d_arr_compact(arr,row,col) \
    for(int tix=0;tix<row;++tix){  \
       print_arr(arr[tix],col)  }

#endif // COMMON_H
