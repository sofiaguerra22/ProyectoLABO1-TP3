#include "cLista.h"

template<class T>
inline cLista<T>::cLista(unsigned int tam)
{
	this->ct = tam; //cantidad total es igual al tamaño

	for (int i = 0; i < ct; i++)
		lista[i] = NULL;
}

template<class T>
inline cLista<T>::~cLista()
{
	if (lista != NULL) {

		for (int i = 0; i < ca; i++)
		{
			if (lista[i] != NULL)
				delete lista[i];
		}
		delete[]lista;
	}
}

template<class T>
inline void cLista<T>::operator+(T* P) // CONSULTAR SI LO HACEMOS BOOL
{
	if (ca < ct) {
		lista[ca++] = P;
	}
	else throw new exception("No hay tamaño suficiente para agregar el item");
	return true;
}

template<class T>
inline void cLista<T>::ImprimirPacientes() //CONSULTAR
{

}

template<class T>
inline T* cLista<T>::operator-(T* P)
{
	T* aux = new T();
	aux = P;
	unsigned int pos = getItemPos(P->getCodigo());
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
inline T* cLista<T>::operator[](unsigned int i)
{
	if (i <= ca)
	{
		return lista[i];
	}
	return NULL;
}

template<class T>
unsigned int cLista<T>::getItemPos(int cod)
{
	for (unsigned int i = 0; i < ca; i++)
	{
		if (lista[i]->getCodigo() == cod)
			return i;
	}

	return -1;
}
