#include "SortAlgorithmn.h"
#include "common.h"

SortAlgorithmn::SortAlgorithmn()
{

}

int SortAlgorithmn::quickSort(int *nums, int count)
{
    int runtimes=0;
    if(count<2)
        return runtimes;

    int i=0;
    int j=count-1;
    while(i<j){
        int sentinal = nums[j];
        while(nums[i]<=sentinal && i < j){
            ++i;
            runtimes++;
        }
        if(i<j){
            nums[j]=nums[i];
            nums[i]=sentinal;
        }

        while(nums[j]>=sentinal && i<j){
            --j;
            runtimes++;
        }
        if(i<j){
            nums[i]=nums[j];
            nums[j]=sentinal;
        }

            runtimes++;

    }
    if(i<count && i>-1){
        print_arr(nums,count);
        quickSort(&nums[0],i);
        quickSort(&nums[i],count-i);
    }

    return runtimes;

}

int SortAlgorithmn::quickSort(vector<int> &v)
{
    stack<int> startStack;
    stack<int> lenStack;
    startStack.push(0);
    lenStack.push(v.size()-1);

    while(!startStack.empty()){
        int start=startStack.top();
        int end=lenStack.top();
        startStack.pop();
        lenStack.pop();

        if(end-start<1){
            continue;
        }

        int i=start;
        int j=end;

        while(i<j){
            while(i<j && v[i]<=v[j]){
                ++i;
            }
            if(i<j){
                int tmp=v[i];
                v[i]=v[j];
                v[j]=tmp;
            }

            while(i<j && v[i]<v[j]){
                --j;
            }
            if(i<j){
                int tmp=v[i];
                v[i]=v[j];
                v[j]=tmp;
            }
        }

        startStack.push(start);
        lenStack.push(i-1);
        startStack.push(i);
        lenStack.push(end);
    }



}

int SortAlgorithmn::qsort(vector<int> &v, vector<int>::iterator l, vector<int>::iterator r)
{
    if(v.size()<2 || l>=r){
        return 1;
    }
    int runtimes=1;

    vector<int>::iterator i=l;
    vector<int>::iterator j=r-1;
    int tmp=0;

    while(i<j){
        ++runtimes;
        while(*i<=*j && i<j){
            ++i;
            ++runtimes;
        }

        if(i<j){
            tmp=*i;
            *i=*j;
            *j=tmp;
            --j;
        }

        while(*i<=*j && i<j){
            --j;
            ++runtimes;
        }

        if(i<j){
            tmp=*i;
            *i=*j;
            *j=tmp;
            ++i;
        }
    }

    runtimes+=qsort(v,l,i);
    runtimes+=qsort(v,++i,r);

    return runtimes;
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
    return times;

}

int SortAlgorithmn::adjustHeap(int *arr, int start, int max)
{
    if(start>=max){
        return 0;
    }
    int times=0;
    for(int root=start;2*root+1<max;){
        int left=root*2+1;
        int right=left+1;
        int pos=(right<max)?((arr[left]>arr[right])?left:right):left;
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
