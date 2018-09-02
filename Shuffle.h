#ifndef SHUFFLE_H
#define SHUFFLE_H


#include <vector>

class Shuffle
{
public:
    Shuffle();

    template<class T>
    static void rightCycleMove(std::vector<T> vec,typename std::vector<T>::iterator start,
                               typename std::vector<T>::iterator split,typename std::vector<T>::iterator stop);

    template<class T>
    static void reverse(typename std::vector<T>::iterator start,typename std::vector<T>::iterator stop);
};

template<class T>
void Shuffle::reverse(typename std::vector<T>::iterator start, typename std::vector<T>::iterator stop)
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
void Shuffle::rightCycleMove(std::vector<T> vec, typename std::vector<T>::iterator start, typename std::vector<T>::iterator split, typename std::vector<T>::iterator stop)
{
    reverse(start,split);
    reverse(split,stop);
    reverse(start,stop);
}

#endif // SHUFFLE_H
