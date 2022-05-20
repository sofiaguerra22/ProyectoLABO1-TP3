#include "cAmbulancia.h"

cAmbulancia::cAmbulancia(string _ID):cVehiculo(_ID)
{
	this->onomatopeya = "iuiuiuiuiu";
	this->tipo = "ambulancia";
}

cAmbulancia::~cAmbulancia()
{
}
