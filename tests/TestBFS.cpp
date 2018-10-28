#include "TestBFS.h"

#include "common.h"
#include "BFS.h"

TestBFS::TestBFS()
{

}

void TestBFS::testDist()
{
    vector<vector<int> > v(10,vector<int>(10,INT_MAX));

    print_2d_arr_raw(v,v.size(),v[0].size());

    cout<<endl;
    BFS::dist(v,5,5,0);

    print_2d_arr_raw(v,v.size(),v[0].size());



}
