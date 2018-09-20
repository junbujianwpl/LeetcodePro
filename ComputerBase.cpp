#include "ComputerBase.h"

#include <bitset>
#include <iostream>
using namespace  std;

ComputerBase::ComputerBase()
{

}

void ComputerBase::printIntBitStr(int n)
{
    bitset<sizeof(n)*8> bit(n);
    cout<<n<<"     "<<bit.to_string()<<endl;

}
