#pragma once
#include "cPaciente.h"
#include "cLista.h"
#include <ctime>
using namespace std;
class cDonante :
public cPaciente{
private:
    cFecha* fechaComienzoAblacion;
    cFecha* fechaFallecimiento;
    cLista<cOrgano>* ListaOrganos;

    cDonante(string _nombre, string _tel, char _sexo, eTipoSangre _sangre, cCentro* _centroAsociado, cFecha* _fechaNacimiento, cFecha* _fechaComienzoAblacion, cFecha* _fechaFallecimiento);
    ~cDonante();
    };


