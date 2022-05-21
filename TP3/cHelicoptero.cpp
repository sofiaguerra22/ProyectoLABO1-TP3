#include "cHelicoptero.h"

cHelicoptero::cHelicoptero(string _ID):cVehiculo(_ID)
{
	this->onomatopeya = "taca-taca-taca";
	this->tipo = "helicoptero";
}
cHelicoptero::~cHelicoptero()
{
}
void cHelicoptero::ImprimirDatos()
{
	cout << this->toString() << endl;
}
string cHelicoptero::toString()
{
	return "Onomatopeya:" + onomatopeya + "\nTipo de vehiculo: " + tipo;
}
