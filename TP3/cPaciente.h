#pragma once
#include <string>
#include <iostream>
#include "cOrgano.h"
#include <ctime>
#include "Enum.h"
#include "cCentro.h"
using namespace std;
class cPaciente
{
	string nombre, tel;
	char sexo;
	eTipoSangre sangre;
	//fecha nacimiento CONSULTAR
	cCentro* centroAsociado;

public:
	cPaciente(string _nombre, string _tel, char _sexo, eTipoSangre _sangre, cCentro* _centroAsociado);
	virtual ~cPaciente();
};

