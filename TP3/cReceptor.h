#pragma once
#include "cPaciente.h"
#include "cLista.h"
using namespace std;
class cReceptor :
    public cPaciente
{
   cFecha* fechaAgregacion;
   cLista<cReceptor>* ListaEspera; 
   cDonante* donanteAsignado;
   cOrgano* organo;
   int prioridad; //1=Verde, 2=Amarillo, 3=Rojo
   int patologia; //relacionado con el enum del organo
   bool estado;

public:
    friend class cListaReceptores;
    friend class cCentro;
    friend class cINCUCAI;
    cReceptor(string _nombre, string _tel, char _sexo, eTipoSangre _sangre, cCentro* _centroAsociado, cFecha* _fechaNacimiento, bool _estado, cOrgano* _organo);
    ~cReceptor();
    cCentro* getCentro() { return centroAsociado; };
    cOrgano* getOrgano() { return organo; };
    cDonante* getDonante() { return donanteAsignado; };
    void setPrioridad(); 
};

