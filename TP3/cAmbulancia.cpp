#include "cAmbulancia.h"

cAmbulancia::cAmbulancia(string _ID):cVehiculo(_ID)
{
	this->onomatopeya = "iuiuiuiuiu";
	this->tipo = "ambulancia";
}

cAmbulancia::~cAmbulancia()
{
}
void cAmbulancia::ImprimirDatos()
{
	cout << this->toString() << endl;
}
string cAmbulancia::toString()
{
	return "Onomatopeya:" + onomatopeya + "\nTipo de vehiculo: " + tipo;
}