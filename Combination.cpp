#include "Combination.h"

Combination::Combination(int count):m_nSize_(count)
{

}

vector<vector<int> > Combination::getNthCombination(int n)
{
    vector<vector<int> > result;
    if(1 > n){
        return result;
    }else if(1 == n){
        for(int i=0;i<=m_nSize_-1;++i){
            result.push_back(vector<int>({i}));
        }
        return result;
    }
    vector<vector<int> > pre=getNthCombination(n-1);
    for(int j=0;j<pre.size();++j) {
        vector<int> v=pre.at(j);
        for(int i=*v.rbegin()+1;i<m_nSize_;++i){
            vector<int> vt=v;
            vt.push_back(i);
            result.push_back(vt);
        }

    }
    return result;
}

vector<vector<vector<int> > > Combination::getNthCombinationGroup(int n, int g)
{
    vector<vector<vector<int> > > result;
    if(n%g !=0 ){
        return result;
    }
    vector<int> idx;
    for(int i=0;i<n;++i){
        idx.push_back(i);
    }
    int eleNum=n/g;
    vector<vector<int> > com=getNthCombination(eleNum);
    for(int i=0;i<com.size();++i){
        vector<int> t=idx;
        eraseFrom(t,com.at(i));
        vector<vector<int> > tmp=splitVec(t,g-1);
        tmp.insert(tmp.begin(),com.at(i));
        result.push_back(tmp);
    }

    return result;
}

vector<vector<int> > Combination::groupByN(int total, int n)
{
    vector<vector<int> > result;
    if(total%n != 0){
        return result;
    }


}

void Combination::eraseFrom(vector<int> &dst, vector<int> &pattern)
{
    vector<int>::iterator iter1,iter2;
    for(iter2=pattern.begin();iter2!=pattern.end();++iter2){
        for(iter1=dst.begin();iter1!=dst.end();++iter1){
            if(*iter1 == *iter2){
                dst.erase(iter1);
                break;
            }
        }
    }
}

vector<vector<int> > Combination::splitVec(const vector<int> &dst, int n)
{
    vector<vector<int> > result;
    if(dst.size()%n != 0){
        return result;
    }
    vector<int> t;
    for(int i=0;i<dst.size();++i){
        t.push_back(dst.at(i));
        if((i+1)%(dst.size()/n) == 0){
            result.push_back(t);
            t.clear();
        }
    }

    return result;
}
