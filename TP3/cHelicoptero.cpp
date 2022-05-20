#include "cHelicoptero.h"

cHelicoptero::cHelicoptero(string _ID):cVehiculo(_ID)
{
	this->onomatopeya = "taca-taca-taca";
	this->tipo = "helicoptero";
}

cHelicoptero::~cHelicoptero()
{
}
