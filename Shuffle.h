#ifndef SHUFFLE_H
#define SHUFFLE_H


#include <vector>
#include <math.h>

#include "common.h"

template<class T>
class Shuffle
{
public:
    Shuffle(const std::vector<T>& vec);

    /**
     * @brief rightCycleMove    right shift a array
     * @param start             start position,included
     * @param stop              stop  position,not include
     * @param num               right shift number
     */
    static void rightCycleMove(typename std::vector<T>::iterator start,
                               typename std::vector<T>::iterator stop,unsigned int num);

    /**
     * @brief reverse     reverse the span
     * @param start       start position
     * @param stop        stop position, not include
     */
    static void reverse(typename std::vector<T>::iterator start,typename std::vector<T>::iterator stop);

    /**
     * @brief findRightShiftPos  find the length (2^n)=log3(K)-1
     * @param start                  start position
     * @param stop					 stop position
     * @param pos                    length (2^n)
     * @return 						 found or not
     */
    static bool findRightShiftPos (typename std::vector<T>::iterator start,typename std::vector<T>::iterator stop,unsigned int & pos);

    /**
     * @brief splitInto2Part   split array into 2 part,one is in perfect length,the remain we can recursivie
     * @param start
     * @param stop
     * @param middle			split position
     * @return
     */
    static bool splitInto2Part(typename std::vector<T>::iterator start, typename std::vector<T>::iterator stop, typename std::vector<T>::iterator &middle);

    /**
     * @brief shuffle   recursive function,split into 2 part, exchange perfect part, and recursive
     * @param start
     * @param stop
     * @return
     */
    static bool shuffle(typename std::vector<T>::iterator start,typename std::vector<T>::iterator stop);

    /**
     * @brief shuffle  shuffle function for object
     * @return
     */
    bool  shuffle();

    std::vector<T> getData() const{return m_vecData__;}

private:
    std::vector<T> m_vecData__;				///< data tobe shuffle
};

template<class S>
Shuffle<S>::Shuffle(const std::vector<S> &vec)
{
    m_vecData__=vec;
}

template<class T>
void Shuffle<T>::reverse(typename std::vector<T>::iterator start, typename std::vector<T>::iterator stop)
{
    typename std::vector<T>::iterator l,r;

    l=start;
    r=stop;
    r--;
    for(;l<r;++l,--r){
        T iter=*l;
        *l=*r;
        *r=iter;
    }
}

template<class T>
bool Shuffle<T>::findRightShiftPos(typename std::vector<T>::iterator start, typename std::vector<T>::iterator stop, unsigned int &pos)
{
    int num=stop-start;
    if (num==0) return true;
    if(num<0 || (num%2)!=0) return false;

    double dlExp=log(double(num+1))/log(double(3));
    int nFloor=floor(dlExp);
    pos=pow(3,nFloor)-1;
    return true;
}

template<class T>
bool Shuffle<T>::splitInto2Part(typename std::vector<T>::iterator start, typename std::vector<T>::iterator stop, typename std::vector<T>::iterator &middle)
{
    int num = stop-start;
    if(num == 0) return true;
    unsigned int pos;
    if(!findRightShiftPos(start,stop,pos))	return false;

    rightCycleMove(start+pos/2,start+num/2+pos/2,pos/2);
    middle=start+pos;
    return true;
}

template<class T>
bool Shuffle<T>::shuffle(typename std::vector<T>::iterator start, typename std::vector<T>::iterator stop)
{
    typename std::vector<T>::iterator middle=stop;
    if(!splitInto2Part(start,stop,middle)) return false;

    int num = middle-start;
    if(num==0) 		 return true;
    else if(num <0) 			 return false;

    int nLog=log(num+1)/log(3);
    if(pow(3,nLog)-1 !=num) return false;

    for(int i=0;i<nLog;++i){
        int head=pow(3,i);
        T temp=*(head+start-1);
        T newest;
        for(int former=2*head%(num+1);former!=head;former=former*2%(num+1)){
            newest=*(start+former-1);
            *(start+former-1)=temp;
            temp=newest;

        }
        *(start+head-1)=temp;
    }


    return shuffle(middle,stop);
}

template<class T>
bool Shuffle<T>::shuffle()
{
   return shuffle(m_vecData__.begin(),m_vecData__.end());
}


template<typename T>
void Shuffle<T>::rightCycleMove( typename std::vector<T>::iterator start, typename std::vector<T>::iterator stop, unsigned int num)
{
    if(num==0) return;
    typename std::vector<T>::iterator split= stop-num%(stop-start);
    reverse(start,split);
    reverse(split,stop);
    reverse(start,stop);
}

#endif // SHUFFLE_H
