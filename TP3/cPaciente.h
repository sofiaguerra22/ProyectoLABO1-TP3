#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include "Enum.h"
#include "cCentro.h"
#include "cFecha.h"
using namespace std;
class cPaciente
{
protected:
	string nombre, tel,dni;
	char sexo;
	eTipoSangre sangre;
	cFecha* fechaNacimiento;
	cCentro* centroAsociado;

public:
	cPaciente(string _nombre, string _tel, char _sexo, eTipoSangre _sangre, cCentro* _centroAsociado, cFecha* _fechaNacimiento, string _dni);
	virtual ~cPaciente();
	string getProvincia() { return centroAsociado->getProvincia(); };
	int getPartido() { return centroAsociado->getPartido(); };
	void ImprimirDatos();
	string toString();
};

