#pragma once
#include "cLista.h"
#include "cReceptor.h"
#include "cDonante.h"
#include <math.h>
using namespace std;
class cListaReceptores :
    public cLista<cReceptor>
{
public:
    cListaReceptores(int _max) :cLista(_max) {};
    ~cListaReceptores();
    cListaReceptores* ReceptoresCompatibles(cDonante* donante);
    cReceptor* ReceptorDefinitivo();
    void reSetDonanteAsignado(cReceptor* receptor);
    void OrdenarPorFecha();
};



