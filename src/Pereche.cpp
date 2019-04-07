#include "Pereche.h"

Pereche::~Pereche()
{
    //dtor
}

Pereche::Pereche(int a, int b)
{
    first = a;
    second = b;
}

int Pereche::getFirst() const
{
    return first;
}

int Pereche::getSecond() const
{
    return second;
}

void Pereche::setFirst(int a)
{
    first = a;
}

void Pereche::setSecond(int a)
{
    second = a;
}

std::istream &operator>>(std::istream &i, Pereche &p)
{
    int x, y;
    i>>x>>y;
    p.setFirst(x);
    p.setSecond(y);
    return i;
}

std::ostream &operator<<(std::ostream &o, const Pereche &p)
{
    o<<p.getFirst()<<" "<<p.getSecond();
    return o;
}

Pereche::Pereche(const Pereche &p)
{
    //std::cout<<std::endl<<p.getFirst()<<" "<<p.getSecond();
    this->first = p.first;
    this->second = p.second;
    //std::cout<<"M-au chemat astia ba";
}

Pereche &Pereche::operator=(const Pereche &p)
{
    //std::cout<<":::"<<std::endl<<p.getFirst()<<" "<<p.getSecond();
    if(this == &p) return *this;
    //if(this == NULL) std::cout<<"DADA";
    //std::cout<<this;
    this->first = 12;
    this->first = p.getFirst();
    this->second = p.getSecond();
    return *this;
}

