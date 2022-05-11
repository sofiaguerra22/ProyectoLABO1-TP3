#include "cINCUCAI.h"

cINCUCAI::cINCUCAI()
{
	cLista<cReceptor>* ListaReceptores = new cLista<cReceptor>;
	cLista<cDonante>* ListaDonantes = new cLista<cDonante>;
	cLista<cCentroSalud>* ListaCentros = new cLista<cCentroSalud>;
}

cINCUCAI::~cINCUCAI()
{
	if (ListaReceptores != NULL)
	{
		for (int i = 0; i < ListaReceptores->getCA(); i++)
		{
			ListaReceptores[i] = NULL;
		}
		delete[]ListaReceptores;
	}
	if (ListaDonantes != NULL)
	{
		for (int i = 0; i < ListaDonantes->getCA(); i++)
		{
			ListaDonantes[i] = NULL;
		}
		delete[]ListaDonantes;
	}
	if (ListaCentros != NULL)
	{
		for (int i = 0; i < ListaCentros->getCA(); i++)
		{
			ListaCentros[i] = NULL;
		}
		delete[]ListaCentros;
	}
}
