#include "Leetcode.h"

#include "SortAlgorithmn.h"
#include <iostream>
#include <QObject>
#include <math.h>

using namespace std;

Leetcode::Leetcode()
{

}

std::vector<std::vector<int> > Leetcode::twoSum(std::vector<int> arr, int dst, int *times)
{
    //return all pairs whos sum equals dst. O(n)=n*logn;
    if(NULL != times){
        *times=0;
    }
    std::vector<std::vector<int> > result;
    if(arr.size()<2)
        return result;

    int runtimes = SortAlgorithmn::quickSort(&arr.at(0),arr.size());

    std::cout<<"qsort runtimes:"<<runtimes<<",len of arr:"<<arr.size()<<std::endl;
    print_arr(arr,arr.size());
    int i=0;
    int j=arr.size()-1;
    while(i<j){
        int sum=arr[i]+arr[j];
        if(sum>dst){
            --j;
        }else if(sum<dst){
            ++i;
        }else{
            std::vector<int> t;
            t.push_back(arr.at(i++));       //avoid repeating use i add to same j
            t.push_back(arr.at(j));
            result.push_back(t);
        }
        ++runtimes;
    }

    if(NULL != times){
        *times=runtimes;
    }
    std::cout<<"twosum runtimes:"<<runtimes<<",len of arr:"<<arr.size()<<",dst:"<<dst<<std::endl;
    return result;

}

std::vector<std::vector<int> > Leetcode::twoSumIndex(std::vector<int> arr, int dst, int *times)
{
    //return all three sum pairs' index whos sum equals dst. O(n)=n*n;

    ///<use a map to save the ele:index pair. use twosum and return the pairs' origin index. so the elements must be unique.

    std::vector<std::vector<int> > result;
    if(NULL != times){
        *times=0;
    }
    if(arr.size()<2){
        return result;
    }

    std::map<int,int> index;
    for(int i=0;i<arr.size();i++) {
        index.insert(std::pair<int,int>(arr.at(i),i));
    }

    std::vector<std::vector<int> > vals=twoSum(arr,dst,times);
    foreach (std::vector<int> vv, vals) {
        std::vector<int> t;
        foreach (int v, vv) {
            t.push_back((*index.find(v)).second);
        }
        result.push_back(t);
    }

    return result;
}

vector<int> Leetcode::twoSumIndexLeet(vector<int> &nums, int target)
{
    vector<int> res;
    vector<int> pos(nums.size(),0);
    for(uint i=0;i<nums.size();++i){
        pos[i]=i;
    }

    stack<vector<int>::iterator> stackStart;
    stack<vector<int>::iterator> stackMap;
    stack<int> stackLen;
    stackStart.push(nums.begin());
    stackLen.push(nums.size());
    stackMap.push(pos.begin());

    while(!stackLen.empty()){
        auto v=stackStart.top();
        auto len=stackLen.top();
        auto m=stackMap.top();

        stackStart.pop();
        stackLen.pop();
        stackMap.pop();

        int i=0,j=len;
        if(j<=1) continue;

        std::cout<<"sentinel "<<*(v+j-1)<<std::endl;
        print_arr(v,len);

        while(i<j-1){
            while(i<j-1 && *(v+i)<=*(v+j-1)) ++i;
            if(i<j-1) {
                swap(*(v+i),*(v+j-1));
                swap(*(m+i),*(m+j-1));
                --j;
            }

            while(i<j-1 && *(v+i)<=*(v+j-1)) --j;
            if(i<j-1) {
                swap(*(v+i),*(v+j-1));
                swap(*(m+i),*(m+j-1));
                ++i;
            }

        }
        print_arr(v,len);
        std::cout<<"CUT "<<i<<std::endl;

        stackStart.push(v);
        stackMap.push(m);
        stackLen.push(i);
        stackStart.push(v+i);
        stackMap.push(m+i);
        stackLen.push(len-i);
    }

    int i=0,j=nums.size();
    while(i<j){
        int sum=nums[i]+nums[j-1];
        if(sum==target){
            res.push_back(pos[i]);
            res.push_back(pos[j-1]);
            break;
        }else if(sum<target){
            ++i;
        }else{
            --j;
        }
    }

    return res;
}

std::vector<std::vector<int> > Leetcode::threeSum(std::vector<int> arr, int dst, int *times)
{
    //return all three sum pairs whos sum equals dst. O(n)=n*n;
    if(NULL != times){
        *times=0;
    }

    std::vector<std::vector<int> > result;
    if(arr.size()<3){
        return result;
    }

    int runtimes=0;
    print_arr(arr,arr.size());
    runtimes+=SortAlgorithmn::quickSort(&*arr.begin(),arr.size());
    int tmp=0;

    for(int i=0;i<arr.size()-2;i++){
        std::vector<std::vector<int> > vv=twoSum(std::vector<int>(arr.begin()+i,arr.end()),dst-arr.at(i),&tmp);
        foreach (std::vector<int> v, vv) {
            v.push_back(arr.at(i));
            result.push_back(v);
        }
        runtimes+=tmp;
    }

    if(NULL != times){
        *times=runtimes;
    }

    return result;
}

int Leetcode::delSame(int *arr, int& len)
{
    //del same element from a sorted arr
    int times=0;

    int j=0;
    for(int i=0;i<len;i++){
        if(arr[j]!=arr[i]){
            arr[++j]=arr[i];
        }
        ++times;
    }

    len=++j;
    return times;
}

int Leetcode::delSameMoreThanN(int *arr, int &len, int max)
{
    //del same ele when the number of same elements exceed max
    int times=0;

    int count=0;
    int j=0;
    for(int i=0;i<len;i++){
        if(arr[j]==arr[i]){
            ++count;
            if(count<=max){
                arr[++j]=arr[i];
            }
        }else{
            count=0;
            arr[++j]=arr[i];
        }
        times++;
    }
    len=++j;

    return times;

}

int Leetcode::delSameMoreThanNBetter(int *arr, int &len, int max)
{
    int times=0;
    int j=max;
    for(int i=max;i<len;i++){
        if(arr[j-max]!=arr[i]){
            arr[j++]=arr[i];
        }
        ++times;
    }
    len=j;
    return times;
}

float Leetcode::getMedianOfTwoSortedArr(int *nums1, int len, int *nums2, int len2)
{
    int runtimes=0;
    int foreval=0;
    int postval=0;
    int idx=0;
    int i=0;
    int j=0;
    while(idx<=(len+len2)/2){

        if(i>=len){
            foreval=postval;
            postval=nums2[j++];
            ++idx;
        }else if(j>=len2){
            foreval=postval;
            postval=nums1[i++];
            ++idx;
        }else{
            if(nums1[i]<nums2[j]){
                foreval=postval;
                postval=nums1[i++];
                ++idx;
            }else if(nums1[i]>nums2[j]){
                foreval=postval;
                postval=nums2[j++];
                ++idx;
            }else{
                foreval=postval;
                postval=nums1[i++];
                ++idx;
            }
        }
        ++runtimes;
    }

    double ret=0.0;

    if((len+len2)%2==0){
        ret=(float(foreval)+float(postval)) /2.0;
    }else{
        ret=postval;
    }

    return ret;
}

int Leetcode::getHIndexOfPaper(vector<int> &citations)
{
    //According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N ? h papers have no more than h citations each."
    //    For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.
    SortAlgorithmn::quickSort(citations);
    int ret=0;
    for(int i=0;i<citations.size();i++){
        int paper_num=citations.size()-i;
        int least_time=citations[i];
        if(least_time>=paper_num){
            ret=(ret>paper_num)?ret:paper_num;
        }
    }
    return ret;
}

bool Leetcode::searchMatrix(vector<vector<int> > &matrix, int target)
{
    if(matrix.empty()){
        return false;
    }
    if(matrix.at(0).empty()){
        return false;
    }

    if(matrix.size()==1 && matrix.at(0).size()==1){
        return matrix.at(0).at(0)==target;
    }

    int maxrow=matrix.size()-1;
    int maxcol=matrix.at(0).size()-1;

    stack<int> stackLow({0,0});
    stack<int> stackHigh({maxrow,maxcol});
    stack<int> stackFix({0,0});
    stack<int> stackDirection({0,1});

    int i,j;
    while(!stackLow.empty()){

        int low=stackLow.top();
        int fix=stackFix.top();
        int high=stackHigh.top();
        int d=stackDirection.top();
        stackLow.pop();
        stackHigh.pop();
        stackFix.pop();
        stackDirection.pop();
        if(low>high){
            continue;
        }
        if(d == 0){
            j=fix;
            i=low+(high-low)/2;
        }else{
            i=fix;
            j=low+(high-low)/2;
        }
        int v=matrix[i][j];
//        std::cout<<target<<" "<<i<<" "<<j<<std::endl;
        if(v == target){
            return true;
        }else if(v>target) {
            stackLow.push(low);
            stackHigh.push(low+(high-low)/2-1);
            stackFix.push(fix);
            stackDirection.push(d);


        }else{
            stackLow.push(low+(high-low)/2+1);
            stackHigh.push(high);
            stackFix.push(fix);
            stackDirection.push(d);

            stackLow.push(fix+1);
            stackHigh.push((d==0)?maxcol:maxrow);
            stackFix.push((d==0)?i:j);
            stackDirection.push(d^1);

        }



    }





    return false;
}

int Leetcode::findKth(vector<int>::const_iterator A, int m, vector<int>::const_iterator B, int n, int k)
{
    assert(k<=m+n && k>0);
    if(m>n) return findKth(B,n,A,m,k);
    if(k==1) return std::min(*B,*A);
    if(m==0) return *(B+k-1);

    int ia=std::min(k/2,m),ib=k-ia;
    if(*(A+ia-1)<*(B+ib-1)) return findKth(A+ia,m-ia,B,ib,k-ia);
    else if(*(A+ia-1)>*(B+ib-1)) return findKth(A,m,B+ib,n-ib,k-ib);
    else return *(A+ia-1);
}

int Leetcode::binarySearch(vector<int> v, int dst)
{
    int i=0,j=v.size();
    while(i<j){
        int pos=(i+j)/2;
        if(v[pos]==dst) return pos;
        else if(v[pos]>dst) j=pos;
        else i=pos+1;
    }
    return -1;
}

int Leetcode::binarySearchFromRotate(vector<int>nums, int target)
{
    int begin=0,end=nums.size(),mid;
    while(begin<end){
        mid=(begin+end)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]>=nums[begin] && nums[mid]>=nums[end-1] ){
            if(nums[mid]<target){
                begin=mid+1;
            }else if(target>=nums[begin]){
                end=mid;
            }else{
                begin=mid+1;
            }
        }else if(nums[mid]<=nums[begin] && nums[mid]<=nums[end-1]){
            if(nums[mid]>target){
                end=mid;
            }else if(target<=nums[end-1]){
                begin=mid+1;
            }else{
                end=mid;
            }
        }else{
            if(nums[mid]>target) end=mid;
            else  begin=mid+1;
        }

    }
    return -1;
}

vector<vector<int>> Leetcode::permute(vector<int>& nums) {

    return permute(nums,0);
}


vector<vector<int>> Leetcode::permute(vector<int> &nums,int start){
    vector<vector<int> > result;
    if(nums.size()-start==0){
        return result;
    }
    if(nums.size()-start==1){
        result.push_back(vector<int>({nums[start]}));
        return result;
    }
    for(uint i=start;i<nums.size();++i){
        int tmp=nums[start];
        nums[start]=nums[i];
        nums[i]=tmp;
        vector<vector<int>> r=permute(nums,start+1);
        for(auto i:r){
            i.insert(i.begin(),nums[start]);
            result.push_back(i);
        }
        tmp=nums[start];
        nums[start]=nums[i];
        nums[i]=tmp;
    }
    return result;
}

int Leetcode::numMatchingSubseq(std::string S, vector<std::string> &words) {
    if(S.empty() || words.empty()){
        return 0;
    }
    map<char,vector<int> > charPos;
    for(int i=0;i<S.size();++i){
        char c=S[i];
        auto iter=charPos.find(c);
        if(iter == charPos.end()){
            charPos.insert(std::pair<char,vector<int>>(c,vector<int>({i})));
        }else{
            (*iter).second.push_back(i);
        }
    }
    int count=0;
    for(auto w:words){
        bool get=true;
        int findStart=-1;
        for(auto c:w){
            auto iter=charPos.find(c);
            if(iter == charPos.end()){
                get=false;
                break;
            }else{
                auto vecPos=(*iter).second;
                bool found=false;
                for(auto pos:vecPos){
                    if(pos>findStart){
                        found=true;
                        findStart=pos;
                        break;
                    }
                }
                if(!found){
                    get=false;
                    break;
                }
            }
        }
        if(get) count++;
    }
    return count;

}

vector<vector<int> > Leetcode::partitionNearestSumSubArr(const vector<int> &arr)
{
    if(arr.size()<2){
        return vector<vector<int> >({arr,vector<int>()});
    }

    vector<int> sortedArr=arr;
    SortAlgorithmn::quickSort(sortedArr);

    int sum=0;

    for(const auto& i : sortedArr) sum+=i;

    auto lClose=sortedArr.begin();
    auto rOpen=sortedArr.begin()+1;

    auto minDist=std::numeric_limits<int>::max();
    int curSum=*sortedArr.begin();
    for(auto i=sortedArr.begin(),j=sortedArr.begin()+1;i<j && j<=sortedArr.end();){
        int curDist=curSum*2-sum;
        cout<<*i<<" "<<*j<<" "<<curSum<<endl;
        if(abs(curDist)<minDist){
            lClose=i;
            rOpen=j;
            minDist=abs(curDist);
            if(minDist == 0) break;
        }
        if(curDist>0){
            curSum-=(*i);
            ++i;
        }else if(curDist<0){
            curSum+=(*j);
            ++j;
        }else{
            lClose=i;
            rOpen=j;
            break;
        }
    }

    vector<int> first;
    first.assign(lClose,rOpen);
    sortedArr.erase(lClose,rOpen);;

    cout<<curSum<<" "<<sum<<endl;

    return vector<vector<int> >({first,sortedArr});
}

void Leetcode::nextPermutation(vector<int> &nums)
{
    int split=nums.size()-1;
    int ceilPos=nums.size()-1;
    bool get=false;
    for(;split>0;--split){
        if(nums[split-1]<nums[split]){
            get=true;
            --split;
            break;
        }
    }
    int l=0;
    if(get){
        int minCeil=std::numeric_limits<int>::max();
        for(int j=nums.size()-1;split<j;--j){
            if(nums[split]<nums[j]){
                if(minCeil>nums[j]){
                    minCeil=nums[j];
                    ceilPos=j;
                }
            }
        }
        swap(nums[split],nums[ceilPos]);
        l=split+1;
    }else{
       l=0;
    }
    for(int i=l,j=nums.size()-1;i<j;++i,--j){
        swap(nums[i],nums[j]);
    }
}









UINT Leetcode::getPrime(UINT idx)
{
    static std::vector<UINT> primes({2,3});

    if(idx<primes.size()){
        return primes.at(idx);
    }

    UINT div=2;
    for(UINT dst=*primes.rbegin()+1;;dst++){
        for(div=2;div<sqrt(dst)+1;div++){
            if(dst%div==0){
                break;
            }
        }
        if(div>sqrt(dst)){
            primes.push_back(dst);
            return dst;
        }
    }
}

std::vector<UINT> Leetcode::getPrimesLessThan(UINT dst)
{
    std::vector<UINT> result;
    UINT prime=0;
    for(UINT i=0;(prime=getPrime(i))<dst;i++){
        result.push_back(prime);
    }
    return result;
}

double Leetcode::sqrt(double d, double loss)
{
    //newton formula.the curve y=f(x).we use the tangent line to simulate its root in some condition.
    //. f(x0)+f'(x0)(x-x0)=y. make y=0. use the line root to simulate root of the curve f(x)=0. get the root
    //and mark it as x1. the we use tangent line at x1 and to get the root and mark it as x2. iter until we
    //get the xn whose loss isn't beyond our expection. f(x0)+f'(x0)(x-x0)=0, x1=x0-f(x0)/f'(x0).
    //so, if we get N as input, we want N^(0.5)=x. so x^2-N=0. then our f(x)=x^2-N. f'(x)=2x.
    //so, x1=x0-(x0^2-N)/2x0=0.5x0+0.5N/x0. make x0=1. f(x0)=1. x1=1-1/2=0.5. x2=x1-(x1^2-N)/2x1
    double x=1.0;
    do{
        x=0.5*x+0.5*d/x;
    }while(fabs(x*x-d)>loss);

    return x;
}

double Leetcode::cubeRoot(double d, double loss)
{
    //as square root before
    //f(x0)+f'(x0)(x-x0)=y.
    //get N as input. we want N^(1/3)=x. so x^3-N=0. the f(x)=x^3-N.
    //f'(x)=3x^2. so x=x0-f(x0)/f'(x0)=x0-(x0^3-N)/(3x0^2)=2x0/3+N/(3x0^2)
    double x=1.0;
    do{
        x=2*x/3+d/(3*x*x);
    }while(fabs(x*x*x-d)>loss);

    return x;
}

std::vector<std::vector<UINT> > Leetcode::getTwoPrimeSumFactor(UINT sum, bool withOne)
{
    std::vector<std::vector<UINT> > result;
    std::vector<UINT> primes=getPrimesLessThan(sum);
    if(withOne){
        primes.insert(primes.begin(),1);
    }

    print_arr(primes,primes.size());

    UINT i=0;
    UINT j=primes.size()-1;

    while(i<j){
        while(i<j && primes.at(i)+primes.at(j)<sum){
            ++i;
        }
        while(i<j && primes.at(i)+primes.at(j)>sum){
            --j;
        }
        if(primes.at(i)+primes.at(j)==sum){
            std::vector<UINT> v({primes.at(i++),primes.at(j)});
            result.push_back(v);
        }
    }
    return result;
}

int Leetcode::findNthDigit(int n)
{
    //Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
    int left=0;
    int right=n;
    int pos=n/2;
    while(right-left>1){
        int val =digitsUntilN(pos);
        if(val<n){
            left=pos;
            pos=(pos+right)/2;
        }else if(val>n){
            right=pos;
            pos=(pos+left)/2;
        }else{
            return pos%10;
        }
    }
    int remain=n-digitsUntilN(right-1);

    return right;
}

int Leetcode::digitsUntilN(int n)
{
    if(n<1)
        return 0;

    vector<int> dig;
    int num=n;
    do{
        int minDig=num%10;
        dig.push_back(minDig);
        num=num/10;
    }while(num!=0);

    int ret=dig.size()*(n-pow(10,dig.size()-1)+1);
    for(unsigned int i=0;i<dig.size()-1;i++){
        ret+=(9*pow(10,i));
    }
    return ret;
}

int Leetcode::reverseInteger(int x)
{
    vector<unsigned int> digits;
    unsigned int xAbs=abs(x);
    unsigned int div=10;
    for(;xAbs;xAbs/=div){
        digits.push_back(xAbs%div);
    }

    unsigned int max=pow(2,31);
    unsigned int reverse=0;
    unsigned int old=0;
    for(unsigned int i=0;i<digits.size();++i){
        if(max-reverse<(digits[i]*pow(10,digits.size()-1-i))) return 0;
        reverse+=(digits[i]*pow(10,digits.size()-1-i));
        if(reverse>pow(2,31) || reverse<old) return 0;
        old=reverse;
    }

    if(x>0 && reverse>(pow(2,31)-1)) return 0;
    if(x<0 && reverse>(pow(2,31))) return 0;

    return (int)((x>=0)?reverse:(-1*reverse));
}

ListNode *Leetcode::addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if(l1 == NULL && l2==NULL) return NULL;
    ListNode *head=new ListNode(0);
    ListNode **cur=&head;
    int flow=0;
    while(l1 || l2 || flow){
        int sum=flow;
        if(l1) {sum+=l1->val; l1=l1->next;}
        if(l2) {sum+=l2->val; l2=l2->next;}
        ListNode *p=new ListNode(sum%10);
        (*cur)->next=p;
        cur=&((*cur)->next);
        flow=sum/10;
    }
    ListNode *ret=head->next;
    delete head;
    return ret;
}

ListNode *Leetcode::sortList(ListNode *head)
{

}

string Leetcode::longestCommonPrefix(vector<string> &strs)
{
    string result;
    if(strs.size()<1 || strs[0].size()<1) return result;

    for(uint i=0;i<strs[0].size();++i){
     uint j=1;
     for(j=1;j<strs.size();++j){
         if(i>=strs[j].size() || strs[0][i] != strs[j][i]){
         break;
         }
     }
     if(j>=strs.size()) result.push_back(strs[0][i]);
     else break;
    }
    return result;
}

ListNode *Leetcode::mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if(NULL == l1) return l2;
    if(NULL == l2) return l1;

    ListNode *head,*cur;
    if(l1->val>l2->val){
        head = l2;
        l2=l2->next;
    }else{
        head=l1;
        l1=l1->next;
    }
    cur=head;

    while(l1 || l2){
        if(NULL == l1) {(cur)->next=l2;break;}
        if(NULL == l2) {(cur)->next=l1;break;}
        if(l1->val < l2->val){
            (cur)->next=l1;
            cur=((cur)->next);
            l1=l1->next;
        }else{
            (cur)->next=l2;
            cur=((cur)->next);
            l2=l2->next;
        }
    }
    return head;
}

ListNode *Leetcode::oddEvenList(ListNode *head)
{
    ListNode oDummy(-1),eDummy(-1),*cur=head,*eTail=&eDummy,*oTail=&oDummy;
    int count=1;
    while(cur){
        cout<<count<<endl;
        if(count++%2==0){
            eTail->next=cur;
            eTail=cur;
        }else{
            oTail->next=cur;
            oTail=cur;
        }
        cur=cur->next;
    }
    if(eTail){
        eTail->next=NULL;
    }
    if(oTail){
        oTail->next=eDummy.next;
    }
    return oDummy.next;
}

