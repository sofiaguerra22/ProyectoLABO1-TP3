#include "cReceptor.h"

cReceptor::cReceptor(string _nombre, string _tel, char _sexo, eTipoSangre _sangre, cCentro* _centroAsociado, cFecha* _fechaNacimiento,bool _estado, cOrgano* _organo):cPaciente(_nombre, _tel, _sexo, _sangre, _centroAsociado, _fechaNacimiento)
{
	this->organo = _organo;
	this->estado = _estado;
	this->patologia = organo->getNumOrgano();
	cLista<cReceptor>* listaEspera = new cLista<cReceptor>;
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
}

void cReceptor::setPrioridad()
{
	int dia = fechaNacimiento->getDia();
	int mes = fechaNacimiento->getMes();
	int anio = fechaNacimiento->getAnio();
	int edad = fechaNacimiento->Edad(dia, mes, anio);
	for (int i = 0; i < ListaEspera->getCA(); i++)
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
	cout << this->toString() << endl;
}
string cReceptor::toString()
{
	return "Patologia:" + to_string(patologia) + "\nPrioridad:" + to_string(prioridad);
}