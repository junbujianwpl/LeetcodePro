#ifndef BALLWEIGHER_H
#define BALLWEIGHER_H

#include <vector>
#include <string>

#include <assert.h>
#include <cstdio>
//#include <stdlib.h>

using std::vector;
using std::string;

class Ball
{
public:
    enum{DEFAULT,NORMAL,UNNORMAL};
    Ball(int val=0,int tag=0):m_nVal_(val),m_nTag_(tag){}

    int getVal() const {return m_nVal_;}
    int getTag() const {return m_nTag_;}
    void setTag(int dst) {m_nTag_=dst;}
    string toString() const{char sz[256];snprintf(sz,sizeof(sz),"val:%d,tag:%d.",m_nVal_,m_nTag_); return sz; }


protected:
    int m_nVal_;			///<value
    int m_nTag_;			///<tag,not tag 0,1 normal,2 unnormal,3 contain unnormal.
};

class BallWeigher
{
public:
    enum{UNKNOWN=-1,BIGGER,SMALLER};
    BallWeigher(int num=12,int times=3,int big=-1);
    virtual ~BallWeigher();

    void compare(vector<int> idx1,vector<int> idx2);

    string getBallsString();

    void compare(vector<Ball*>& g1,vector<Ball*>& g2);

    static int sumBallVal(const vector<Ball*>& g);

    static int isAllNormal(const vector<Ball*>& g);

protected:
    int m_nBallNum_;
    int m_nTimes_;
    int m_nBigOrSmall_;
    vector<Ball*> m_vecBalls_;
};

#endif // BALLWEIGHER_H
