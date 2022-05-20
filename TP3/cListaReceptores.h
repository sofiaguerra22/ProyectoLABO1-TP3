#pragma once
#include "cLista.h"
#include "cReceptor.h"
#include "cDonante.h"
using namespace std;
class cListaReceptores :
    public cLista<cReceptor>
{
public:
    cListaReceptores(int _max) :cLista(_max) {};
    ~cListaReceptores();
    cLista<cReceptor>* ReceptoresCompatibles(cDonante* donante)
    {
        cLista<cReceptor>* subLista = new cLista<cReceptor>;
        cLista<cOrgano>* ListaOrganos = donante->ListaOrganos->getLista();
        int i, j= 0;
        for (i = 0; i < donante->ListaOrganos->getCA(); i++) //recorre cada órgano del donante
        {
            for (j = 0; j < ca; j++) //ca es la cantidad actual de receptores
            {
                if ((*ListaOrganos)[i] == lista[j]->getOrgano() && donante->sangre == lista[j]->sangre)

                {
                    *subLista + lista[j]; //uso del operator +
                }
            }
        }
        return subLista;
    };
};

