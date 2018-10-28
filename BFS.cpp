#include "BFS.h"

BFS::BFS()
{

}

void BFS::dist(vector<vector<int> > &v, int x, int y,int distance)
{

    queue<pair<int,int> > spos;
    spos.push(make_pair(x,y));

    vector<vector<bool> > used(v.size(),vector<bool>(v[0].size(),false));

    v[x][y]=min(v[x][y],distance);
    used[x][y]=true;
    int step[][2]={{1,0},
                   {-1,0},
                   {0,-1},
                   {0,1}};


    while(!spos.empty()){
        auto p=spos.front();
        spos.pop();

        int i=p.first,j=p.second;
        distance=v[i][j]+1;
        cout<<"get x:"<<i<<",y:"<<j<<"   ";

        for(int k=0;k<4;++k){
            int nx=i+step[k][0];
            int ny=j+step[k][1];
            if(nx>=0 && ny>=0 && nx<v.size() && ny<v[0].size() && !used[nx][ny]){
                v[nx][ny]=distance;
                spos.push(make_pair(nx,ny));
                cout<<"pushed: x:"<<nx<<",y:"<<ny<<";  ";
                used[nx][ny]=true;
            }
            cout<<endl;

        }

    }
}
