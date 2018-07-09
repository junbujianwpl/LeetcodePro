#ifndef YANGHUITRIANGLE_H
#define YANGHUITRIANGLE_H

#include<vector>
#include<string>

class YangHuiTriangle
{
public:
    YangHuiTriangle(int nLines);

    std::vector<uint32_t> getTriangle() const;
    std::vector<std::vector<uint32_t> > getTriangle2D() const;

    void printTriangle() const;

private:

    uint32_t m_nLines__;											///<total lines

    uint32_t m_nMaxEle__;											///<max element in the triangle

    uint32_t m_nMaxEleWidth__;										///<digits in max element

    std::vector<uint32_t>  m_vecTriangle__;							///<triangle array

};

#endif // YANGHUITRIANGLE_H
