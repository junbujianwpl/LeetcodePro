#include "DFS.h"

#include "common.h"

using namespace std;

DFS::DFS()
{

}

NQueen::NQueen(int num):m_nQueenNum__(num)
{

}

std::vector<std::vector<int> > NQueen::getLayout()
{
    vector<vector<int> > v(m_nQueenNum__,vector<int>(m_nQueenNum__,NQueen::Init));
    for(int i=0;i<m_nQueenNum__;i++){
        vector<vector<int> > vv=v;
        dirtyBoard(vv,0,i);
        vv[0][i]=NQueen::Used;
        findPostion(vv,m_nQueenNum__-1);
        print_2d_arr_compact(vv,m_nQueenNum__,m_nQueenNum__);
        cout<<endl;
    }
    findPostion(v,m_nQueenNum__);
    return v;
}

bool NQueen::findPostion(std::vector<std::vector<int> > &board, int num)
{
    if(num<1){
        return true;
    }

    int r=board.size();

    for(int i=0;i<r;i++){
        for(int j=0;j<r;j++){
            if(board[i][j]==NQueen::Init){
                vector<vector<int> > v=board;
                dirtyBoard(board,i,j);
                board[i][j]=NQueen::Used;
                if(findPostion(board,num-1)){
                    return true;
                }else{
                    board=v;
                    continue;
                }
            }
        }
    }
    return false;
}

void NQueen::dirtyBoard(std::vector<std::vector<int> > &board, int row, int col, int fillVal)
{
    int r=board.size();

    //dirty row col
    for(int i=0;i<r;i++){
        board[row][i]=fillVal;
        board[i][col]=fillVal;
    }

    //dirty diagonal
    for(int i=row,j=col;i<r && j<r;i++,j++){
        board[i][j]=fillVal;
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        board[i][j]=fillVal;
    }
    //dirty vice-diagonal
    for(int i=row,j=col;i>=0 && j<r;i--,j++){
        board[i][j]=fillVal;
    }
    for(int i=row,j=col;i<r && j>=0;i++,j--){
        board[i][j]=fillVal;
    }

}

