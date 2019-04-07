#ifndef STIVA_PERECHE_H
#define STIVA_PERECHE_H

#include "Multime_Pereche.h"

class Stiva_Pereche: public Multime_Pereche
{
    public:
        Stiva_Pereche();
        Stiva_Pereche(int n, const Pereche &p);
        Stiva_Pereche(const Stiva_Pereche &sp);
        //E de ajuns operator= al clasei de baza
        using Multime_Pereche::operator=;
        ~Stiva_Pereche();
        Pereche &Get() const;
        void AddPereche(const Pereche &p);
        void Delete();

        friend std::istream &operator>>(std::istream &i, Stiva_Pereche &sp);
        friend std::ostream &operator<<(std::ostream &o, const Stiva_Pereche &sp);

    protected:

    private:
};

#endif // STIVA_PERECHE_H
