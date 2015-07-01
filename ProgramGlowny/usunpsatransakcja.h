#ifndef USUNPSATRANSAKCJA_H
#define USUNPSATRANSAKCJA_H
#include "transakcja.h"
#include <QTableView>

class UsunPsaTransakcja : public Transakcja
{
public:
    UsunPsaTransakcja(QTableView *widok);
    virtual void wykonaj();

private:
    QTableView* widok;
};

#endif // USUNPSATRANSAKCJA_H
