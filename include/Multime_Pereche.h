#ifndef MULTIME_PERECHE_H
#define MULTIME_PERECHE_H

#include "Pereche.h"

class Multime_Pereche
{
    public:
        Multime_Pereche();
        Multime_Pereche(int n, const Pereche &p);
        Multime_Pereche(const Multime_Pereche &mp);
        ~Multime_Pereche();
        Multime_Pereche &operator=(const Multime_Pereche &mp);
        int GetCount() const;
        virtual void AddPereche(const Pereche &p);
        //Pereche Get(int pos) const;
        virtual Pereche &Get() const;
        virtual void Delete();

        friend std::istream &operator>>(std::istream &i, Multime_Pereche &mp);
        friend std::ostream &operator<<(std::ostream &o, const Multime_Pereche &mp);

    protected:
        int count;
        Pereche *arr;
    private:

};

#endif // MULTIME_PERECHE_H
