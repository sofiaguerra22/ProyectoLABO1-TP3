#pragma once
#include <string>
#include <iostream>
using namespace std;
#define TMAX 100
template <class T> 
class cLista
{
	T** lista;
	unsigned int ca, ct;

public:
	cLista(unsigned int tam = TMAX);
	~cLista();

	bool operator+(T* P); //P= puntero que recibe, m�todo agregar
	void ImprimirPacientes(); //imprime el listado de receptores y donantes
	T* operator-(T* P); //sobrecarga del operator - para quitar elementos
	T* operator[](unsigned int i); //se le pasa la posici�n y devuelve el puntero
	unsigned int getItemPos(int cod);
	unsigned int getCA() { return ca; };
	//falta sobrecarga ostream

};

