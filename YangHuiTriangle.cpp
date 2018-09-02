#include "YangHuiTriangle.h"

#include<iostream>

using namespace std;

YangHuiTriangle::YangHuiTriangle(int nLines):m_nLines__(nLines),m_nMaxEle__(0),m_nMaxEleWidth__(1)
{
    vector<uint32_t> vecLast;
    for(uint32_t i=0;i<m_nLines__;++i){
        vector<uint32_t> vecCur;
        if(i<2){
            vecCur.assign(i+1,1);
            m_nMaxEle__=1;
        }else{
            vecCur.push_back(1);
            for(uint32_t j=1;j<vecLast.size();++j){
                uint32_t u32Ele=vecLast.at(j)+vecLast.at(j-1);
                vecCur.push_back(u32Ele);
                m_nMaxEle__=max(m_nMaxEle__,u32Ele);
            }
            vecCur.push_back(1);
        }
        m_vecTriangle__.insert(m_vecTriangle__.end(),vecCur.begin(),vecCur.end());
        vecLast=vecCur;
    }

    m_nMaxEleWidth__=1;

    for(uint32_t base=10;m_nMaxEle__/base;base*=10){
        ++m_nMaxEleWidth__;
    }

}

std::vector<uint32_t> YangHuiTriangle::getTriangle() const
{
    return m_vecTriangle__;
}



std::vector<std::vector<uint32_t> > YangHuiTriangle::getTriangle2D() const
{
    vector<vector<uint32_t> > vecRet;
    uint32_t nLines=0;
    for(uint32_t i=0;i<m_vecTriangle__.size();++nLines){
        vector<uint32_t> vecLine;
        for(uint32_t j=0;j<nLines+1;++j){
            vecLine.push_back(m_vecTriangle__.at(i++));
        }
        vecRet.push_back(vecLine);
    }
    return vecRet;
}

void YangHuiTriangle::printTriangle() const
{
    string strSpace(m_nMaxEleWidth__,' ');
    int nLine=0;
    for(uint32_t i=0;i<m_vecTriangle__.size();++nLine){
        //print line align
        string strAlgin((m_nLines__-nLine)*m_nMaxEleWidth__,' ');
        cout<<strAlgin.c_str();
        for(int j=0;j<nLine+1;++j){
            char szTxt[256];
            snprintf(szTxt,sizeof(szTxt),"%*d",m_nMaxEleWidth__,m_vecTriangle__.at(i++));
            cout<<szTxt<<strSpace.c_str();
        }
        cout<<endl;
    }
}
