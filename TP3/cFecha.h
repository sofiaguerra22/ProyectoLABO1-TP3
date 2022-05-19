#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

class cFecha
{
private:
#pragma region Atributos

	tm fecha;

#pragma endregion	

#pragma region Constructor y Destructor

public:
	//Constructor por default, inicia en la fecha de hoy
	cFecha();

	//Constructor inicia en dia, mes, a�o
	cFecha(int d, int m, int a);

	cFecha(int dia, int mes, int anio, int hora, int minutos);

	~cFecha();

#pragma endregion

#pragma region Metodos

	//Calcula el numero de d�as entre dos fechas
	static int DiasEntreFechas(cFecha* inicio, cFecha* fin);


	//Cambia la fecha a la fecha actual
	void SetHoy();

	//Verifica que la fecha est� completa
	bool FechaCompleta();

	//Devuelve la fecha actual en forma de string
	string To_string();

	// Imprime fecha
	void ImprimirFecha();

	// Determina si las dos fechas tiene el mismo dia
	static bool MismoDia(cFecha* fecha1, cFecha* fecha2);

#pragma endregion

#pragma region Sobrecarga de Operadores

	bool operator<(cFecha& otra) {
		time_t aux_this = mktime(&(this->fecha));
		time_t aux_otra = mktime(&(otra.fecha));
		return aux_this < aux_otra;
	}

	bool operator>(cFecha& otra) {
		time_t aux_this = mktime(&(this->fecha));
		time_t aux_otra = mktime(&(otra.fecha));
		return aux_this > aux_otra;
	}

	bool operator==(cFecha& otra) {
		time_t aux_this = mktime(&(this->fecha));
		time_t aux_otra = mktime(&(otra.fecha));
		return aux_this == aux_otra;
	}

	bool operator!=(cFecha& otra) {
		return !(*this == otra);
	}

#pragma endregion
};
