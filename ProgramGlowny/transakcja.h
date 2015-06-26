#ifndef TRANSAKCJA_H
#define TRANSAKCJA_H

class Transakcja
{
public:
    Transakcja() {}
    virtual void wykonaj() = 0;
};

#endif // TRANSAKCJA_H
