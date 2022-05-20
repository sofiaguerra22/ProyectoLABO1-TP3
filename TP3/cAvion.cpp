#include "cAvion.h"

cAvion::cAvion(string _ID):cVehiculo(_ID)
{
	this->onomatopeya = "zhooooooom";
	this->tipo = "avion"; 
}

cAvion::~cAvion()
{
}
