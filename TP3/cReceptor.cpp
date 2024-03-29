#include "cReceptor.h"

cReceptor::cReceptor(string _nombre, string _tel, char _sexo, eTipoSangre _sangre, cCentro* _centroAsociado, cFecha* _fechaNacimiento, string _dni, bool _estado, cOrgano* _organo) :cPaciente(_nombre, _tel, _sexo, _sangre, _centroAsociado, _fechaNacimiento, _dni)
{
	this->organo = _organo;
	this->estado = _estado;
	this->patologia = organo->getNumOrgano();
	this->ListaEspera = new cLista<cReceptor>;
	fechaNacimiento = new cFecha();
	fechaNacimiento = _fechaNacimiento;
	fechaAgregacion = new cFecha();
	fechaAgregacion->SetHoy();
	this->prioridad = 0;
	donanteAsignado = NULL;
	setPrioridad();
}

cReceptor::~cReceptor()
{
	if (ListaEspera != NULL)
	{
		for (unsigned int i = 0; i < ListaEspera->getCA(); i++)
		{
			ListaEspera[i] = NULL;
		}
		delete[] ListaEspera;
	}
	if (fechaNacimiento != NULL)
		delete fechaNacimiento;
	if (fechaAgregacion != NULL)
		delete fechaAgregacion;
	if (organo != NULL)
		delete organo;
	if (centroAsociado != NULL)
		delete centroAsociado;
}

void cReceptor::setPrioridad()
{
	int dia = fechaNacimiento->getDia();
	int mes = fechaNacimiento->getMes();
	int anio = fechaNacimiento->getAnio();
	int edad = fechaNacimiento->Edad(dia, mes, anio);
	for (unsigned int i = 0; i < ListaEspera->getCA(); i++)
	{
		if (edad != -1)
		{
			if (edad <= 35 && estado == false)
			{
				prioridad = 3;
			}
			if (edad <= 35 && estado == true)
			{
				prioridad = 1;
			}
			if (edad > 35 && estado == false)
			{
				prioridad = 3;
			}
			if (edad > 35 && estado == true)
			{
				prioridad = 2;
			}
		}
	}
}
void cReceptor::ImprimirDatos()
{
	cout << "Datos Receptor:" << endl;
	cout << "Nombre paciente:" + nombre + "\nTelefono paciente:" + tel +
		"\nDNI:" + dni + "\nFecha nacimiento: " + fechaNacimiento->To_string() + "\ntipo sangre:" + TipoSangreToString(sangre) << endl;
	cout << "Centro Asociado:" + centroAsociado->toString() << endl;
}

bool cReceptor::operator==(cDonante* donante)
{
	if (sangre == donante->getTipoSangre())
		return true;
	return false;
}
