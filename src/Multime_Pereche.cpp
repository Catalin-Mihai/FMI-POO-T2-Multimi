#include "Multime_Pereche.h"

Multime_Pereche::Multime_Pereche()
{
    count = 0;
    arr = NULL;
    //std::cout<<"Multime_Pereche()"<<std::endl;
}

Multime_Pereche::Multime_Pereche(int n, const Pereche &p)
{
    count = n;
    arr = new Pereche[n];
    for(int i = 0; i < n; i++)
    {
        arr->setFirst(p.getFirst());
        arr->setSecond(p.getSecond());
    }
}

Multime_Pereche::Multime_Pereche(const Multime_Pereche &mp)
{
    //std::cout<<"M a chemat";
    this->count = mp.GetCount();
    if(this->count > 0)
    {
        this->arr = new Pereche[this->count];
        for(int i = 0; i < this->count; i++)
        {
            //std::cout<<std::endl<<this->arr[i].getFirst()<<" "<<this->arr[i].getSecond();
            this->arr[i] = mp.arr[i];
        }
    }
    else this->arr = NULL;
}

Multime_Pereche::~Multime_Pereche()
{
    delete[] arr;
}

int Multime_Pereche::GetCount() const
{
    return this->count;
}

Multime_Pereche &Multime_Pereche::operator=(const Multime_Pereche &mp)
{
    //std::cout<<"CALLED";
    if(this == &mp) return *this;
    delete[] this->arr;
    this->arr = new Pereche[mp.GetCount()];
    this->count = mp.count;
    for(int i = 0; i < mp.GetCount(); i++)
    {
        this->arr[i] = mp.arr[i];
    }
    return *this;
}

Pereche &Multime_Pereche::Get() const
{
    //Ramane riscul utilizatorului sa acceseze o casuta inexistenta
    //if(pos < count)
        return this->arr[this->count];
}

void Multime_Pereche::Delete()
{
    Multime_Pereche temp = *this;//Copie a variabilei

    if(this->count > 0)
    {
        delete[] this->arr; //stergem vectorul
        this->count--;//Scadem dimensiunea vectorului cu 1
        this->arr = new Pereche[this->count]; //Construim altul cu dimensiunea noua (-1)
        for(int i = 0; i < temp.count; i++) //Copiere vector in vechi in cel nou
        {
            //std::cout<<"da";
            this->arr[i] = temp.arr[i];
        }
    }
}

void Multime_Pereche::AddPereche(const Pereche &p)
{
    //std::cout<<std::endl<<p.getFirst()<<" "<<p.getSecond();
    Multime_Pereche temp = *this;//Copie a variabilei
    //std::cout<<std::endl<<temp;
    if(this->count > 0) delete[] this->arr; //stergem vectorul
    this->count++;//Crestem dimensiunea vectorului cu 1
    this->arr = new Pereche[this->count]; //Construim altul cu dimensiunea noua (+1)
    for(int i = 0; i < temp.count; i++) //Copiere vector in vechi in cel nou
    {
        //std::cout<<"da";
        this->arr[i] = temp.arr[i];
    }
    //Inseram valorile necesare noii intrari.
    this->arr[count-1].setFirst(p.getFirst());
    this->arr[count-1].setSecond(p.getSecond());
}

std::istream &operator>>(std::istream &i, Multime_Pereche &mp)
{
    delete[] mp.arr;
    mp.count = 0;
    mp.arr = NULL;
    Pereche p;
    int nr = 0;
    std::cout<<std::endl<<"Cate perechi doriti sa cititi?"<<std::endl;
    i>>nr;
    while(nr > 0)
    {
        i>>p;
        mp.AddPereche(p);
        nr--;
    }
    return i;
}

std::ostream &operator<<(std::ostream &o, const Multime_Pereche &mp)
{
    for(int i = 0; i < mp.GetCount(); i++)
    {
        o<<mp.arr[i]<<" | ";
    }
    return o;
}
