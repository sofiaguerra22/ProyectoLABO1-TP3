#include "cPaciente.h"

cPaciente::cPaciente(string _nombre, string _tel, char _sexo, eTipoSangre _sangre, cCentro* _centroAsociado, cFecha* _fechaNacimiento), dni(_dni) //averiguar que onda
{
	this->centroAsociado = _centroAsociado;
	this->nombre = _nombre;
	this->sangre = _sangre;
	this->sexo = _sexo;
	this->tel = _tel;
	this->fechaNacimiento = _fechaNacimiento;
	//this->dni = _dni;
}

cPaciente::~cPaciente()
{
	if (centroAsociado != NULL)
		centroAsociado = NULL;
	if (fechaNacimiento != NULL)
		fechaNacimiento = NULL;
}
void cPaciente::ImprimirDatos()
{
	cout << this->toString() << endl;
}
string cPaciente::toString() 
{
	return "DNI: " + nombre + "\nSexo: " + to_string(sexo) + "\nTelefono: " + tel;
}