#ifndef SHUFFLE_H
#define SHUFFLE_H


#include <vector>

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

private:
    std::vector<T> m_vecData__;				///< data tobe shuffle
};

template<class S>
Shuffle<S>::Shuffle(const std::vector<S> &vec)
{

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


template<typename T>
void Shuffle<T>::rightCycleMove( typename std::vector<T>::iterator start, typename std::vector<T>::iterator stop, unsigned int num)
{
    typename std::vector<T>::iterator split= stop-num%(stop-start);
    reverse(start,split);
    reverse(split,stop);
    reverse(start,stop);
}

#endif // SHUFFLE_H
