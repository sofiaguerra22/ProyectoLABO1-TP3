#include "cAvion.h"

cAvion::cAvion(string _ID):cVehiculo(_ID)
{
	this->onomatopeya = "zhooooooom";
	this->tipo = "avion"; 
}

cAvion::~cAvion()
{
}
void cAvion::ImprimirDatos()
{
	cout << this->toString() << endl;
}
string cAvion::toString()
{
	return "Onomatopeya:" + onomatopeya + "\nTipo de vehiculo: " + tipo;
}
