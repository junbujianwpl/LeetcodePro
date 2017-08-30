
#include "SortAlgorithmn.h"
#include "common.h"

int main(int argc,char** argv){

    std::cout<<"hello world"<<std::endl;
    int arr[]={1,2,9,2,4,5,222,29,20};
    print_arr(arr,ARR_SIZE(arr));
    SortAlgorithmn::heapSort(arr,ARR_SIZE(arr));
    print_arr(arr,ARR_SIZE(arr));
}
