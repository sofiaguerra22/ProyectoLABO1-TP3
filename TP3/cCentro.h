#pragma once
#include "cVehiculo.h"
#include <string>
#include <iostream>
#include "cLista.h"
using namespace std;
class cCentro
{
	string nombre, direccion, provincia, telefono;
	int partido;
	cLista<cVehiculo>* listaVehiculos;
public:
	cCentro(string _nombre, string _direccion, string _provincia, string _telefono, int _partido);
	~cCentro();
	void AsignarVehiculo();
	void IniciarAblacion();
	void RealizarTrasplante();
};

