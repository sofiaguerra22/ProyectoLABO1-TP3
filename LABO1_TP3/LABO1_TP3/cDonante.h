#pragma once
#include "cPaciente.h"
#include "cLista.h"
#include <ctime>
using namespace std;
class cDonante :
    public cPaciente
{
    //fecha y hora de fallecimiento CONSULTAR
    //fecha y hora de comienzo de ablacion
    cLista<cOrgano>* ListaOrganos;

    cDonante();
    ~cDonante();
};

