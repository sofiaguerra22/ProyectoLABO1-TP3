#include "cDonante.h"

cDonante::cDonante(string _nombre, string _tel, char _sexo, eTipoSangre _sangre, cCentro* _centroAsociado, cFecha* _fechaNacimiento, string _dni, cFecha* _fechaFallecimiento) :cPaciente(_nombre, _tel, _sexo, _sangre, _centroAsociado, _fechaNacimiento, _dni)
{
	fechaComienzoAblacion = NULL;
	this->fechaFallecimiento = _fechaFallecimiento;
	this->ListaOrganos = new cLista<cOrgano>;
	/*for (int i = 0; i < ListaOrganos->; i++) {
		ListaOrganos[i] = NULL;
	}*/
	cantOrganos = 0;
}
cDonante::~cDonante()
{
	delete ListaOrganos;
	/*if (ListaOrganos != NULL)
	{
		for (unsigned int i = 0; i < (ListaOrganos->getCA()); i++)
		{
			ListaOrganos[i] = NULL;
		}
		delete ListaOrganos;
	}*/
	fechaComienzoAblacion = NULL;
	fechaFallecimiento = NULL;
}
void cDonante::setListaOrganos(cLista<cOrgano>* _listaOrganos)
{
	cantOrganos = ListaOrganos->getCA();
	for (int i = 0; i < cantOrganos; i++) {
		ListaOrganos[i] = _listaOrganos[i];
	}
}
void cDonante::ImprimirDatos()
{
	cout << "Datos donante:" + this->toString() << endl;
	cout<< "Nombre paciente:" + nombre + "\nTelefono paciente:" + tel + 
	"\nFecha nacimiento:" + fechaNacimiento->To_string() + "\nDNI:" + dni + "\nFecha fallecimiento: " + fechaFallecimiento->To_string() << endl;
	cout << "\nCentro Asociado:" + centroAsociado->toString() << endl;
}
string cDonante::toString()
{
	return "\nCantidad de organos donante:" + to_string(cantOrganos);
}

