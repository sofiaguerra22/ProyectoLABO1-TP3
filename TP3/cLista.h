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
	unsigned int getItemPos(T* P);
	unsigned int getCA() { return ca; };
	bool Agregar(T* P);
	T* Quitar(T* P);
	bool Eliminar(T* P);
	T* BuscarenPos(int i);

};

template<class T>
 cLista<T>::cLista(unsigned int tam)
{
	this->ca = 0;
	this->ct = tam; //cantidad total es igual al tama�o

	for (unsigned int i = 0; i < ct; i++)
	{
		lista[i] = NULL;
	}
}

template<class T>
 cLista<T>::~cLista()
{
	if (lista != NULL) {

		for (unsigned int i = 0; i < ca; i++)
		{
			lista[i] = NULL;
		}
		delete[]lista;
	}
}

template<class T>
 bool cLista<T>::operator+(T* P) // al agregar se asegura que el elemento no exista en la lista
{
	 int i = 0;
	 if (ca < ct && P != NULL) {
		 for (unsigned i = 0; i < ca + 1; i++) //la �ltima posicion va a ser null asi que no puede ser igual
		 {
			 if (lista[i] == P)
				 break;
		 }
	 }
	 if (i != 0 && i != ca + 1)
		 return true;
	 return false;
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
	 T* aux = NULL;
	aux = P;
	int pos = getItemPos(P);
	if (pos != -1)
	{
		ca--;
		for (unsigned int j = pos; j < ca; j++)
		{
			lista[j] = lista[j + 1];
		}

		lista[ca] = NULL;
		return aux;
	}
	return NULL;
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
