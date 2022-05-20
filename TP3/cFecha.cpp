#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include "cFecha.h"
cFecha::cFecha() {
	fecha.tm_hour = 0;
	fecha.tm_min = 0;
	fecha.tm_sec = 0;
	fecha.tm_mday = 0;
	fecha.tm_mon = 0;
	fecha.tm_year = 0;
	SetHoy();
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

cFecha::cFecha(int d, int m, int a)
{
	fecha.tm_hour = 0;
	fecha.tm_min = 0;
	fecha.tm_sec = 0;
	fecha.tm_mday = d;
	fecha.tm_mon = m - 1;
	fecha.tm_year = a - 1900;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

cFecha::cFecha(int d, int m, int a, int hs, int min) {

	fecha.tm_hour = hs;
	fecha.tm_min = min;
	fecha.tm_sec = 0;
	fecha.tm_mday = d;
	fecha.tm_mon = m - 1;
	fecha.tm_year = a - 1900;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

cFecha::~cFecha() {
}

int cFecha::HorasEntreFechas(cFecha* inicio, cFecha* fin)
{
	int dif = 0;
	time_t aux_inicio = mktime(&(inicio->fecha)); //paso las fechas a segundos
	time_t aux_fin = mktime(&(fin->fecha));

	//verifico que las fechas que recibo no sean null ni est�n incompletas
	if ((inicio != NULL && fin != NULL) && inicio->FechaCompleta() && fin->FechaCompleta())
	{
		//verifico que fecha fin > fecha inicio con operador sobrecargado
		if (*inicio > *fin)
			throw exception("Las fechas no son v�lidas");
		else
		{
			dif = difftime(aux_fin, aux_inicio) / (3600); //calculo la diferencia en horas
			return dif;
		}
	}
	else throw exception("Fechas incompletas");
}


void cFecha::SetHoy()
{
	time_t now = time(0);
	tm* aux = localtime(&now); //obtengo fecha actual
	fecha.tm_mday = aux->tm_mday;
	fecha.tm_mon = aux->tm_mon;
	fecha.tm_year = aux->tm_year;
	fecha.tm_hour = aux->tm_hour;
	fecha.tm_min = aux->tm_min;
}

bool cFecha::FechaCompleta()
{
	if (fecha.tm_year != 0 && fecha.tm_mon != 0 && fecha.tm_mday != 0) //verifico que los par�metros de d�a no est�n en sus valores nulos
		return true;
	return false;
}

//string cFecha::To_string()
//{
//	return to_string(fecha.tm_year + 1900) +
//		"/" + to_string(fecha.tm_mon + 1) +
//		"/" + to_string(fecha.tm_mday);
//}
//
//void cFecha::ImprimirFecha() {
//	cout << To_string() << endl;;
//}
//
//bool cFecha::MismoDia(cFecha* fecha1, cFecha* fecha2)
//{
//	if (fecha1->fecha.tm_wday == fecha2->fecha.tm_wday)
//		return true;
//	else
//		return false;
//}