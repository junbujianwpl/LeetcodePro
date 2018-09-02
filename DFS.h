#ifndef DFS_H
#define DFS_H

#include<bits/stdc++.h>


class DFS
{
public:
    DFS();
};


class NQueen
{
public:
    NQueen(int num = NQueen::DefaultNum);

    /**
     * @brief getLayout get NQueen layout
     * @return  board represented by 2d-vector
     */
    std::vector<std::vector<int> > getLayout();

private:
    enum {Bad=0,Used=1,Init=2,DefaultNum=8};

    /**
     * @brief findPostion from the board find a init place to take one queen
     * @param board
     * @param num   how many queens need to arrange
     * @return   true when all queens arranged or false
     */
    bool findPostion(std::vector<std::vector<int> >& board,int num);

    /**
     * @brief dirtyBoard dirty same row col and diagonal from given position on the board
     * @param board
     * @param row
     * @param col
     * @param fillVal
     */
    void dirtyBoard(std::vector<std::vector<int> >& board,int row,int col,int fillVal=NQueen::Bad);

    int m_nQueenNum__;
};

#endif // DFS_H
