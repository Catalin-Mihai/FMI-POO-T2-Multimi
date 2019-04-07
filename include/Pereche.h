#ifndef PERECHE_H
#define PERECHE_H

#include <iostream>

class Pereche
{
    public:
        Pereche(int a = 0, int b = 0);
        Pereche(const Pereche &p);
        ~Pereche();
        void setFirst(int a);
        int getFirst() const;
        void setSecond(int a);
        int getSecond() const;
        Pereche &operator=(const Pereche &p);

    protected:

    private:
        int first;
        int second;
};

std::istream &operator>>(std::istream &i, Pereche &p);
std::ostream &operator<<(std::ostream &o, const Pereche &p);

#endif // PERECHE_H
