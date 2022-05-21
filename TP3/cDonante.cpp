#include "cDonante.h"

cDonante::cDonante(string _nombre, string _tel, char _sexo, eTipoSangre _sangre, cCentro* _centroAsociado, cFecha* _fechaNacimiento, string _dni, cFecha* _fechaComienzoAblacion, cFecha* _fechaFallecimiento) :cPaciente(_nombre, _tel, _sexo, _sangre, _centroAsociado, _fechaNacimiento, _dni)
{
	this->fechaComienzoAblacion = _fechaComienzoAblacion;
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
	cout << this->toString() << endl;
}
string cDonante::toString()
{
	return "Cantidad de organos:" + to_string(cantOrganos);
}
//void cDonante::setCantOrganos()
//{
//	cantOrganos = ListaOrganos->getCA();
//}
