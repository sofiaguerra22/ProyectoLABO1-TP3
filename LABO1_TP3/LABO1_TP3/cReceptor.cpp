#include "cReceptor.h"

cReceptor::cReceptor(bool _estado, cOrgano* _organo)
{
	this->organo = _organo;
	this->estado = _estado;
	this->patologia = organo->getNumOrgano();
	this->prioridad = setPrioridad();
}

cReceptor::~cReceptor()
{
}

int cReceptor::setPrioridad()
{
	//dependiendo la edad, el estado y su posicion en la lista
}
