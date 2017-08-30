#include "SortAlgorithmn.h"
#include "common.h"

SortAlgorithmn::SortAlgorithmn()
{

}

void SortAlgorithmn::quickSort(int *nums, int count)
{
    if(count<2)
        return;

    int i=0;
    int j=count-1;
    while(i<j){
        int sentinal = nums[j];
        while(nums[i]<sentinal && i < j){
            ++i;
        }
        if(i<j){
            nums[j]=nums[i];
            nums[i]=sentinal;
        }

        while(nums[j]>=sentinal && i<j){
            --j;
        }
        if(i<j){
            nums[i]=nums[j];
            nums[j]=sentinal;
        }
    }
    if(i<count && i>-1){
        print_arr(nums,count);
        quickSort(&nums[0],i);
        quickSort(&nums[i],count-i);
    }


}

int SortAlgorithmn::heapSort(int *arr, int len)
{
    int times=0;
    for(int i=len/2;i>-1;i--){
        times+=adjustHeap(arr,i,len);
    }
    std::cout<<"after first adjust"<<std::endl;
    print_arr(arr,len);

    for(int i=1;i<len;i++){
        int tmp=arr[0];
        arr[0]=arr[len-i];
        arr[len-i]=tmp;

        times+=adjustHeap(arr,0,len-i);
        print_arr(arr,len);
    }


}

int SortAlgorithmn::adjustHeap(int *arr, int start, int max)
{
    if(start<=max){
        return 0;
    }
    int times=0;
    for(int root=start;2*root+2<max;){
        int left=root*2+1;
        int right=left+1;
        int pos=(arr[left]>arr[right])?left:right;
        if(arr[root]<arr[pos]){
            int tmp=arr[root];
            arr[root]=arr[pos];
            arr[pos]=tmp;
            root=pos;
        }else{
            break;
        }
        times++;
    }
    return times;
}
