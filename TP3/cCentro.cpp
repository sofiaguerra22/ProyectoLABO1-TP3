#include "cCentro.h"
#include "cDonante.h"
#include"cReceptor.h"
#include "cOrgano.h"

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
		for (int i = 0; i < (listaVehiculos->getCA()); i++)
		{
			listaVehiculos[i] = NULL;
		}
		delete[]listaVehiculos;
	}
}

cVehiculo* cCentro::AsignarVehiculo(cDonante* donante, cReceptor* receptor)
{
	if (donante->getProvincia() == receptor->getProvincia())
	{
		if (donante->getPartido() == receptor->getPartido())
		{
			for (int i = 0; i < (listaVehiculos->getCA()); i++)
			{
				if ((*listaVehiculos)[i]->getTipo() == "ambulancia")
					return (*listaVehiculos)[i];
			}
		}
		if (donante->getPartido() != receptor->getPartido())
		{
			for (int i = 0; i < (listaVehiculos->getCA()); i++)
			{
				if ((*listaVehiculos)[i]->getTipo() == "helicoptero")
					return (*listaVehiculos)[i];
			}

		}
	}
	else if (donante->getProvincia() != receptor->getProvincia())
	{
		for (int i = 0; i < (listaVehiculos->getCA()); i++)
		{
			if ((*listaVehiculos)[i]->getTipo() == "avion")
				return (*listaVehiculos)[i];
		}
	}
	return NULL;
	
}


bool cCentro::IniciarAblacion(cReceptor* receptor, cOrgano* _organo, cVehiculo* vehiculoAsignado)
{
	if (receptor != NULL && _organo != NULL && vehiculoAsignado != NULL)
	{
		cDonante* donante = receptor->donanteAsignado;
		donante->fechaComienzoAblacion->SetHoy();
		(*donante->ListaOrganos) - _organo;
		return true;
	}
	return false;
	//RealizarTransporte(vehiculoAsignado, receptor);
}

bool cCentro::RealizarTransporte(cVehiculo* vehiculo, cReceptor* receptor)
{
	cAmbulancia* ambulancia_aux = dynamic_cast<cAmbulancia*>(vehiculo);
	cHelicoptero* helicoptero_aux = dynamic_cast<cHelicoptero*>(vehiculo);
	cAvion* avion_aux = dynamic_cast<cAvion*>(vehiculo);
	cCentro* centro_receptor = receptor->centroAsociado;
	if (ambulancia_aux != NULL)
	{
		cout << "" << ambulancia_aux->getOnomatopeya() <<"\nAmbulancia llego a destino"<< endl;
		return true;
	}
	if (helicoptero_aux != NULL)
	{
		cout << "" << helicoptero_aux->getOnomatopeya() <<"\nHelicoptero llego a destino"<< endl;
		return true;
	}
	if (avion_aux != NULL)
	{
		cout << "" << avion_aux->getOnomatopeya() <<"\nAvion llego a destino"<< endl;
		return true;
	}
	return false;
}

bool cCentro::RealizarTrasplante(cReceptor* receptor)
{
	cFecha* fechaActual = new cFecha();
	fechaActual->SetHoy();
	cDonante* donanteAsignado = receptor->donanteAsignado;
	cFecha* fechaInicio = donanteAsignado->fechaComienzoAblacion;
	int horas = fechaActual->HorasEntreFechas(fechaInicio, fechaActual);
	if (horas <= 20)
	{
		int random = 1 + (rand() % 100);
		if (random % 2 == 0)
		{
			return true;
		}
		if (random % 2 != 0)
			return false;
	}
	return false;
}
void cCentro::ImprimirDatos()
{
	cout << this->toString() << endl;
}
string cCentro::toString() {
	return "Nombre:" + nombre + "\nDireccion: " + direccion + "\nProvincia: " + provincia + "\nTelefono: " + telefono 
		+ "\nPartido: " +to_string(partido);
}
