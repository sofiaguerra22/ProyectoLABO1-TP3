#pragma once
#include "cPaciente.h"
#include "cLista.h"
using namespace std;
class cReceptor :
    public cPaciente
{
   cFecha* fechaAgregacion;
   cLista<cReceptor>* ListaEspera; 
   cOrgano* organo;
   int prioridad; //1=Verde, 2=Amarillo, 3=Rojo
   int patologia; //relacionado con el enum del organo
   bool estado;

public:
    cReceptor(string _nombre, string _tel, char _sexo, eTipoSangre _sangre, cCentro* _centroAsociado, cFecha* _fechaNacimiento, bool _estado, cOrgano* _organo,cFecha *fechaAgregacion);
    ~cReceptor();
    int setPrioridad(); //se necesita ctime
};

