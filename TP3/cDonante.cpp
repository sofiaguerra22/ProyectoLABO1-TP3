#include "cDonante.h"

cDonante::cDonante(string _nombre, string _tel, char _sexo, eTipoSangre _sangre, cCentro* _centroAsociado, cFecha* _fechaNacimiento,cFecha* _fechaComienzoAblacion, cFecha* _fechaFallecimiento) :cPaciente(_nombre,_tel,_sexo, _sangre, _centroAsociado, _fechaNacimiento)
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
		for (int i = 0; i < ListaOrganos->getCA(); i++)
		{
			ListaOrganos[i] = NULL;
		}
		delete[] ListaOrganos;
	}
	fechaComienzoAblacion = NULL;
	fechaFallecimiento = NULL;
}

//void cDonante::setCantOrganos()
//{
//	cantOrganos = ListaOrganos->getCA();
//}
