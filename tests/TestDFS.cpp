#include "TestDFS.h"

using namespace std;

TestDFS::TestDFS()
{

}

void TestDFS::testGetLayout()
{
    vector<vector<int> > v=NQueen().getLayout();
    print_2d_arr_compact(v,v.size(),v.size());
}
