#pragma once
#include "cPaciente.h"
#include "cLista.h"
using namespace std;
class cReceptor :
    public cPaciente
{
    //fecha de agregacion
  // cLista<cReceptor>* ListaEspera; //CONSULTAR
   cOrgano* organo;
   int prioridad; //1=Verde, 2=Amarillo, 3=Rojo
   int patologia; //relacionado con el enum del organo
   bool estado;

public:
    cReceptor(bool _estado, cOrgano* _organo);
    ~cReceptor();
    int setPrioridad();
};

