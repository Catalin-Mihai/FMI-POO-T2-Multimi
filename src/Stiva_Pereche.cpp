#include "Stiva_Pereche.h"

Stiva_Pereche::Stiva_Pereche(){}

Stiva_Pereche::Stiva_Pereche(int n, const Pereche &p): Multime_Pereche(n, p){}

Stiva_Pereche::Stiva_Pereche(const Stiva_Pereche &sp) : Multime_Pereche(sp) {}

Stiva_Pereche::~Stiva_Pereche(){}

Pereche &Stiva_Pereche::Get() const
{
    return this->arr[0];
}

void Stiva_Pereche::Delete()
{
    Stiva_Pereche temp = *this;//Copie a variabilei

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

void Stiva_Pereche::AddPereche(const Pereche &p)
{
    Stiva_Pereche temp = *this;//Copie a variabilei
    if(this->count > 0) delete[] this->arr; //stergem vectorul
    this->count++;//Crestem dimensiunea vectorului cu 1
    this->arr = new Pereche[this->count]; //Construim altul cu dimensiunea noua (+1)
    for(int i = 1; i <= temp.count; i++) //Copiere vector in vechi in cel nou
    {
        //std::cout<<"da";
        this->arr[i] = temp.arr[i-1];
    }
    //Inseram valorile necesare noii intrari.
    this->arr[0].setFirst(p.getFirst());
    this->arr[0].setSecond(p.getSecond());
}

std::istream &operator>>(std::istream &i, Stiva_Pereche &sp)
{
    Multime_Pereche *ptr = (Multime_Pereche*)(&sp);
    i>>(*ptr);
    return i;
}

std::ostream &operator<<(std::ostream &o, const Stiva_Pereche &sp)
{
    Multime_Pereche *ptr = (Multime_Pereche*)(&sp);
    o<<(*ptr);
    return o;
}

