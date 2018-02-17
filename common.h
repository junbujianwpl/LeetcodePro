#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <string>

using std::string;

#define ARR_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))


#define print_arr(arr,len) \
    std::cout<<len<<":num "; \
    for(int iix=0;iix<len;iix++) \
    std::cout<<arr[iix]<<" ";            \
    std::cout<<std::endl;           \


#define print_2d_arr(arr,row,col) \
    for(int tix=0;tix<row;++tix){  \
       std::cout<<tix<<std::endl;   \
       print_arr(arr[tix],col)  }


#endif // COMMON_H
