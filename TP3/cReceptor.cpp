#include "cReceptor.h"

cReceptor::cReceptor(string _nombre, string _tel, char _sexo, eTipoSangre _sangre, cCentro* _centroAsociado, cFecha* _fechaNacimiento,bool _estado, cOrgano* _organo, cFecha *_fechaAgregacion):cPaciente(_nombre, _tel, _sexo, _sangre, _centroAsociado, _fechaNacimiento)
{
	this->organo = _organo;
	this->estado = _estado;
	this->patologia = organo->getNumOrgano();
	this->prioridad = setPrioridad();
	cLista<cReceptor>* listaEspera = new cLista<cReceptor>;
	this->fechaAgregacion = _fechaAgregacion;
}

cReceptor::~cReceptor()
{
}

int cReceptor::setPrioridad()
{
	//dependiendo la edad, el estado y su posicion en la lista

}
