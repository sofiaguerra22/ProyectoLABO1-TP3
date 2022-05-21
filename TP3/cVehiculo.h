#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;
class cVehiculo
{
	string ID;
	string tipo;
public:
	cVehiculo(string _ID);
	virtual ~cVehiculo();
	string getTipo() { return tipo; };
	void ImprimirDatos();
	string toString();
};

