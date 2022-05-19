#include "cDonante.h"

cDonante::cDonante(string _nombre, string _tel, char _sexo, eTipoSangre _sangre, cCentro* _centroAsociado, cFecha* _fechaNacimiento,cFecha* _fechaComienzoAblacion, cFecha* _fechaFallecimiento) :cPaciente(_nombre,_tel,_sexo, _sangre, _centroAsociado, _fechaNacimiento)//consultar
{

}
cDonante::~cDonante()
{

}
