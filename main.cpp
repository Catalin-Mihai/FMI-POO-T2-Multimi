#include <iostream>

#include "Pereche.h"
#include "Multime_Pereche.h"
#include "Stiva_Pereche.h"
#include "Coada_Pereche.h"

using namespace std;

int main()
{
    Coada_Pereche c1;
    Stiva_Pereche s;
    Coada_Pereche c2;
    cin>>c1;
    cout<<endl<<"Coada 1: "<<c1;
    int marime = c1.GetCount();

    //Scoatem elemente din c1 si bagam in stiva, iar din stiva inapoi in c2;
    for(int i = 0; i < marime; i++)
    {
        s.AddPereche(c1.Get());
        c1.Delete();
    }
    cout<<endl<<"Stiva: "<<s;
    marime = s.GetCount();
    for(int i = 0; i < marime; i++)
    {
        c2.AddPereche(s.Get());
        s.Delete();
    }
    cout<<endl<<"Coada 2: "<<c2;
    //c2.Delete();
    //cout<<endl<<"Coada 2: "<<c2;
    return 0;
}
