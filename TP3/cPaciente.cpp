#include "cPaciente.h"

cPaciente::cPaciente(string _nombre, string _tel, char _sexo, eTipoSangre _sangre, cCentro* _centroAsociado, cFecha* _fechaNacimiento)
{
	this->centroAsociado = _centroAsociado;
	this->nombre = _nombre;
	this->sangre = _sangre;
	this->sexo = _sexo;
	this->tel = _tel;
	this->fechaNacimiento = _fechaNacimiento;
}

cPaciente::~cPaciente()
{
}
