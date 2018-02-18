#include "BallWeigher.h"


BallWeigher::BallWeigher(int num, int times, int big):m_nBallNum_(num),m_nTimes_(times),m_nBigOrSmall_(big)
{
    for(int i=0;i<num;++i){
        m_vecBalls_.push_back(new Ball((i+1)/num));
    }
}

BallWeigher::~BallWeigher()
{
    for(int i=0;i<m_vecBalls_.size();++i){
        delete m_vecBalls_.at(i);
    }

}

void BallWeigher::compare(vector<int> idx1, vector<int> idx2)
{
    assert(idx1.size() == idx2.size());
    vector<Ball*> v1,v2;
    vector<int>::iterator iter1,iter2;
    for(iter1=idx1.begin(),iter2=idx2.begin();iter1!=idx1.end() && iter2!=idx2.end();++iter1,++iter2){
        assert(*iter1 < m_vecBalls_.size());
        assert(*iter2 < m_vecBalls_.size());
        assert(*iter1 != *iter2);
        v1.push_back(m_vecBalls_.at(*iter1));
        v2.push_back(m_vecBalls_.at(*iter2));
    }
    compare(v1,v2);
}

std::string BallWeigher::getBallsString()
{
    string result;
    vector<Ball*>::iterator iter=m_vecBalls_.begin();
    for(;iter!=m_vecBalls_.end();++iter){
        result.append((*iter)->toString());
        result.append("|  ");
    }
    return result;
}

void BallWeigher::compare(vector<Ball *> &g1, vector<Ball *> &g2)
{
    if(g1.size()<1 || g2.size()<1){
        return;
    }

    int sum1=sumBallVal(g1);
    int sum2=sumBallVal(g2);


    if(sum1 == sum2){
        for(int i=0;i<g1.size();++i){
            g1.at(i)->setTag(Ball::NORMAL);
        }
        for(int i=0;i<g2.size();++i){
            g2.at(i)->setTag(Ball::NORMAL);
        }
    }else{
        if(g1.size()==1 && 1==g2.size() && m_nBigOrSmall_>UNKNOWN){
            if(m_nBigOrSmall_ == BIGGER){
                if(sum1>sum2){
                    g1.at(0)->setTag(Ball::UNNORMAL);
                }else{
                    g2.at(0)->setTag(Ball::UNNORMAL);
                }
            }else{
                if(sum1<sum2){
                    g1.at(0)->setTag(Ball::UNNORMAL);
                }else{
                    g2.at(0)->setTag(Ball::UNNORMAL);
                }
            }
        }else if(g1.size()>1){
            if(isAllNormal(g1)){
                if(sum1>sum2){
                    m_nBigOrSmall_=SMALLER;
                }else{
                    m_nBigOrSmall_=BIGGER;
                }
            }else if(isAllNormal(g2)){
                if(sum1<sum2){
                    m_nBigOrSmall_=SMALLER;
                }else{
                    m_nBigOrSmall_=BIGGER;
                }
            }
        }
    }
}

int BallWeigher::sumBallVal(const vector<Ball *> &g)
{
    int sum=0;
    for(int i=0;i<g.size();++i){
        sum+=g.at(i)->getVal();
    }
    return sum;
}

int BallWeigher::isAllNormal(const vector<Ball *> &g)
{
    if(g.empty())
        return 0;
    for(int i=0;i<g.size();++i){
        if(g.at(i)->getTag() != Ball::NORMAL)
            return 0;
    }
    return 1;
}
