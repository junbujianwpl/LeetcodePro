#ifndef COMBINATION_H
#define COMBINATION_H

#include <vector>

using std::vector;

class Combination
{
public:
    Combination(int count);

    /**
     * @brief getNthCombination get n elements combination index. every ele only combine ele after the ele to make sure no repeat
     * @param n  elements number
     * @return   all n element combination
     */
    vector<vector<int> > getNthCombination(int n);

    /**
     * @brief getNthCombinationGroup get g n-elements group combination, element not repeat among group
     * @param n number every group
     * @param g group num
     * @return
     */
    vector<vector<vector<int> > > getNthCombinationGroup(int n,int g);


    static vector<vector<int> > groupByN(int total,int n);

protected:
    int m_nSize_;

    void eraseFrom(vector<int>& dst, vector<int> &pattern);

    vector<vector<int> > splitVec(const vector<int>& dst,int n);
};

#endif // COMBINATION_H
