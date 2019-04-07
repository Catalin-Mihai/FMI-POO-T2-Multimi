#ifndef COADA_PERECHE_H
#define COADA_PERECHE_H

#include "Multime_Pereche.h"

class Coada_Pereche: public Multime_Pereche
{
    public:
        Coada_Pereche();
        Coada_Pereche(int n, const Pereche &p);
        Coada_Pereche(const Coada_Pereche &sp);
        //E de ajuns operator= al clasei de baza
        using Multime_Pereche::operator=;
        ~Coada_Pereche();
        Pereche &Get() const;
        void AddPereche(const Pereche &p);
        void Delete();

        friend std::istream &operator>>(std::istream &i, Coada_Pereche &cp);
        friend std::ostream &operator<<(std::ostream &o, const Coada_Pereche &cp);

    protected:

    private:
};

#endif // COADA_PERECHE_H
