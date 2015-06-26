#ifndef REJESTR_H
#define REJESTR_H

#include <QList>

class WydaniePsa;
class Rejestr
{
public:
    Rejestr();

private:
    QList<WydaniePsa*> listaWydan;
};

#endif // REJESTR_H
