#pragma once
//#include "cVehiculo.h"
#include <string>
#include <iostream>
#include "cLista.h"
#include "cOrgano.h"
#include "cAmbulancia.h"
#include "cHelicoptero.h"
#include "cAvion.h"
#include <math.h>
using namespace std;
class cReceptor;
class cDonante;
class cCentro
{
	string nombre, direccion, provincia, telefono;
	int partido;
	cLista<cVehiculo>* listaVehiculos;
public:
	cCentro(string _nombre, string _direccion, string _provincia, string _telefono, int _partido);
	~cCentro();
	cVehiculo* AsignarVehiculo(cDonante* donante, cReceptor* receptor);
	bool IniciarAblacion(cReceptor* receptor, cOrgano* _organo, cVehiculo* vehiculoAsignado);
	bool RealizarTransporte(cVehiculo* vehiculo, cReceptor* receptor);
	bool RealizarTrasplante(cReceptor* receptor);
	string getProvincia() { return provincia; };
	int getPartido() { return partido; };
	void ImprimirDatos();
	string toString();
};

