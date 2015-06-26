#include "rejestr.h"
#include "klient.h"
#include "pies.h"

Rejestr gRejestr;

Rejestr::Rejestr()
{

}

void Rejestr::dodaj(WydaniePsa *wydaniePsa)
{
    listaWydan.append(wydaniePsa);
}

Pies *Rejestr::getPies(int id)
{
    for(QList<WydaniePsa*>::iterator it = listaWydan.begin();
        it != listaWydan.end(); ++it ) {
        Pies* wskPies = (*it)->getPies();
           if( wskPies->getId() == id )
               return wskPies;
    }
    return 0;
}

Klient *Rejestr::getKlient(int id)
{
    for(QList<WydaniePsa*>::iterator it = listaWydan.begin();
        it != listaWydan.end(); ++it ) {
        Klient* wskKlient = (*it)->getKlient();
           if( wskKlient->getId() == id )
               return wskKlient;
    }
    return 0;
}

void Rejestr::wyczysc()
{
    listaWydan.clear();
}

