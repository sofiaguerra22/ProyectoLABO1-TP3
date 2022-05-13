#pragma once
#include "cLista.h"
#include "cReceptor.h"
#include "cDonante.h"
using namespace std;
class cListaReceptores :
    public cLista
{
    cLista<cReceptor>** listaReceptores;
public:
    cListaReceptores();
    ~cListaReceptores();
    cLista<cReceptor>* BuscarReceptores(cDonante* donante);
};

