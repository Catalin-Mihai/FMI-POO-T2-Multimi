#include "Coada_Pereche.h"

Coada_Pereche::Coada_Pereche(){}

Coada_Pereche::Coada_Pereche(int n, const Pereche &p): Multime_Pereche(n, p){}

Coada_Pereche::Coada_Pereche(const Coada_Pereche &sp) : Multime_Pereche(sp) {}

Coada_Pereche::~Coada_Pereche(){}

Pereche &Coada_Pereche::Get() const
{
    return this->arr[0];
}

void Coada_Pereche::Delete()
{
    Coada_Pereche temp = *this;//Copie a variabilei

    if(this->count > 0)
    {
        delete[] this->arr; //stergem vectorul
        this->count--;//Scadem dimensiunea vectorului cu 1
        this->arr = new Pereche[this->count]; //Construim altul cu dimensiunea noua (-1)
        for(int i = 1; i <= temp.count; i++) //Copiere vector in vechi in cel nou
        {
            //std::cout<<"da";
            this->arr[i-1] = temp.arr[i];
        }
    }
}

void Coada_Pereche::AddPereche(const Pereche &p)
{
    return Multime_Pereche::AddPereche(p);
}

std::istream &operator>>(std::istream &i, Coada_Pereche &cp)
{
    Multime_Pereche *ptr = (Multime_Pereche*)(&cp);
    i>>(*ptr);
    return i;
}

std::ostream &operator<<(std::ostream &o, const Coada_Pereche &cp)
{
    Multime_Pereche *ptr = (Multime_Pereche*)(&cp);
    o<<(*ptr);
    return o;
}

