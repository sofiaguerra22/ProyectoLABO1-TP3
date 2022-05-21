#pragma once
#include <string>
#include <iostream>
using namespace std;
#define TMAX 100
template <class T>
class cLista
{
protected:
	T** lista;
	unsigned int ca, ct;

public:
	cLista(unsigned int tam = TMAX);
	virtual ~cLista();

	bool operator+(T* P); //P= puntero que recibe, m�todo agregar
	void ImprimirPacientes(); //imprime el listado de receptores y donantes
	T* operator-(T* P); //sobrecarga del operator - para quitar elementos
	T* operator[](unsigned int i); //se le pasa la posici�n y devuelve el puntero
	unsigned int getItemPos(int cod);
	unsigned int getCA() { return ca; };
	//cLista<T>* getLista() { return lista; };
	//falta sobrecarga ostream

};

template<class T>
 cLista<T>::cLista(unsigned int tam)
{
	this->ct = tam; //cantidad total es igual al tama�o

	for (int i = 0; i < ct; i++)
		lista[i] = NULL;
}

template<class T>
 cLista<T>::~cLista()
{
	if (lista != NULL) {

		for (int i = 0; i < ca; i++)
		{
			lista[i] = NULL;
		}
		delete[]lista;
	}
}

template<class T>
 bool cLista<T>::operator+(T* P) // AGREGAR CONDICIONES DE CONSIGNA 
{
	if (ca < ct) {
		lista[ca++] = P;
	}
	else throw new exception("No hay tama�o suficiente para agregar el item");
	return true;
}

template<class T>
bool cLista<T>::Agregar(T* P)
{
	if (P != NULL && ca < ct)
	{
		lista[ca] = P;
		ca++;
		return true;
	}
	return false;
}

template<class T>
 void cLista<T>::ImprimirPacientes() //CONSULTAR
{

}

template<class T>
 T* cLista<T>::operator-(T* P)
{
	T* aux = new T();
	aux = P;
	int cod = P->getCodigo();
	unsigned int pos = getItemPos(cod);
	if (cod != -1)
	{
		ca--;
		for (unsigned int j = pos; j < ca; j++)
		{
			lista[j] = lista[j + 1];
		}

		lista[ca] = NULL;
		return aux;
	}
}

template<class T>
T* cLista<T>::Quitar(T* P)
{
	if (P == NULL)
		return NULL;
	int pos = getItemPos(P);
	if (pos != -1)
	{
		ca--; //disminuimos la cantidad actual
		T* aux = P; //igualamos el aux al puntero en la posici�n para despues devolverlo
		for (int i = pos; i < ca; i++)
		{
			lista[i] = lista[i + 1];
		}
		lista[pos] = NULL; //quitamos el puntero
		return aux; //devolvemos el auxiliar creado
	}
	return NULL;
}

template<class T>
bool cLista<T>::Eliminar(T* P)
{
	T* aux = Quitar(P);
	if (aux != NULL)
	{
		aux = NULL;
		return true;
	}
	return false;
}

template<class T>
 T* cLista<T>::operator[](unsigned int i)
{
	if (i <= ca)
	{
		return lista[i];
	}
	return NULL;
}

template<class T>
unsigned int cLista<T>::getItemPos(T* P)
{
	for (unsigned int i = 0; i < ca; i++)
	{
		if (lista[i] == P)
			return i;
	}

	return -1;
}

template<class T>
T* cLista<T>::BuscarenPos(int i)
{
	if (i <= ca)
	{
		return lista[i];
	}
}
