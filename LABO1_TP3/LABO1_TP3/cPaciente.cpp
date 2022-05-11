#include "cPaciente.h"

cPaciente::cPaciente(string _nombre, string _tel, char _sexo, eTipoSangre _sangre, cCentroSalud* _centroAsociado)
{
	this->centroAsociado = _centroAsociado;
	this->nombre = _nombre;
	this->sangre = _sangre;
	this->sexo = _sexo;
	this->tel = _tel;
}

cPaciente::~cPaciente()
{
}
