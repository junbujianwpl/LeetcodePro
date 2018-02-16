#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <string>

using std::string;

#define ARR_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))


#define print_arr(arr,len) \
    std::cout<<len<<":num "; \
    for(int i=0;i<len;i++) \
    std::cout<<arr[i]<<" ";            \
    std::cout<<std::endl;           \



#endif // COMMON_H
