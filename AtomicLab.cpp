#include "AtomicLab.h"

AtomicLab::AtomicLab()
{

}

void AtomicLab::addSafe(int n)
{
    m_allData__.fetch_add(n);

}

void AtomicLab::addNoSafe(int n)
{
    m_llData__+=n;
}

void AtomicLab::print()
{
    cout<<m_llData__<<endl<<m_allData__<<endl;
}
