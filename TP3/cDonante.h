#pragma once
#include "cPaciente.h"
#include <ctime>
using namespace std;
class cDonante :
public cPaciente{
private:
    cFecha* fechaComienzoAblacion;
    cFecha* fechaFallecimiento;
    cLista<cOrgano>* ListaOrganos;
    int cantOrganos; //si podemos entrar a la clase, esto no es necesario

public:
    friend class cListaReceptores; //para poder acceder al �rgano
    friend class cCentro;
    cDonante(string _nombre, string _tel, char _sexo, eTipoSangre _sangre, cCentro* _centroAsociado, cFecha* _fechaNacimiento, string _dni,cFecha* _fechaFallecimiento);
    ~cDonante();
    eTipoSangre getTipoSangre() { return sangre; };
    cLista<cOrgano>* getListaOrganos() { return ListaOrganos; };
    cCentro* getCentro() { return centroAsociado; };
    void ImprimirDatos();
    string toString();
    void setListaOrganos(cLista<cOrgano>*_listaOrganos);
    };


