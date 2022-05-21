#include "cVehiculo.h"

cVehiculo::cVehiculo(string _ID)
{
	this->ID = _ID;
}

cVehiculo::~cVehiculo()
{
}
void cVehiculo::ImprimirDatos()
{
	cout << this->toString() << endl;
}
string cVehiculo::toString()
{
	return "ID:" + ID;
}
