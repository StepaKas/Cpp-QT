#include "neco.h"

class NecoData : public QSharedData
{
public:

};

Neco::Neco() : data(new NecoData)
{

}

Neco::Neco(const Neco &rhs) : data(rhs.data)
{

}

Neco &Neco::operator=(const Neco &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Neco::~Neco()
{

}
