#include "cCentro.h"

cCentro::cCentro(string _nombre, string _direccion, string _provincia, string _telefono, int _partido)
{
	this->nombre = _nombre;
	this->direccion = _direccion;
	this->provincia = _provincia;
	this->telefono = _telefono;
	this->partido = _partido;
	cLista<cVehiculo>* listaVehiculos = new cLista<cVehiculo>;
}

cCentro::~cCentro()
{
	if (listaVehiculos != NULL)
	{
		for (int i = 0; i < listaVehiculos->getCA(); i++)
		{
			listaVehiculos[i] = NULL;
		}
		delete[]listaVehiculos;
	}
}

void cCentro::AsignarVehiculo()
{
}

void cCentro::IniciarAblacion()
{
}

void cCentro::RealizarTrasplante()
{
}
