#include "cDonante.h"

cDonante::cDonante(string _nombre, string _tel, char _sexo, eTipoSangre _sangre, cCentro* _centroAsociado, cFecha* _fechaNacimiento, string _dni, cFecha* _fechaFallecimiento) :cPaciente(_nombre, _tel, _sexo, _sangre, _centroAsociado, _fechaNacimiento, _dni)
{
	fechaComienzoAblacion = 0;
	this->fechaFallecimiento = _fechaFallecimiento;
	this->ListaOrganos = new cLista<cOrgano>;
	cantOrganos = 0;
}
cDonante::~cDonante()
{
	if (ListaOrganos != NULL)
	{
		for (unsigned int i = 0; i < (ListaOrganos->getCA()); i++)
		{
			ListaOrganos[i] = NULL;
		}
		delete[] ListaOrganos;
	}
	fechaComienzoAblacion = NULL;
	fechaFallecimiento = NULL;
}
void cDonante::ImprimirDatos()
{
	cout << "Datos Donante:" + this->toString() << endl;
	cout<< "Nombre paciente:" + nombre + "\nTelefono paciente:" + tel + 
	"\nFecha nacimiento:" + fechaNacimiento->To_string() + "\nDNI:" + dni + "\nFecha fallecimiento: " + fechaFallecimiento->To_string() << endl;
	cout << "\nCentro Asociado:" + centroAsociado->toString() << endl;
}
string cDonante::toString()
{
	return "\nCantidad de organos Donante:" + to_string(cantOrganos);
}

void cDonante::setListaOrganos(cLista<cOrgano>*_listaOrganos)
{
	cantOrganos = _listaOrganos->getCA();
	for (int i = 0; i < _listaOrganos->getCA(); i++) {
		(ListaOrganos)[i] = (_listaOrganos[i]);
	}
}

