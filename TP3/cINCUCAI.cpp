#include "cINCUCAI.h"

cINCUCAI::cINCUCAI()
{
	cLista<cReceptor>* ListaReceptores = new cLista<cReceptor>;
	cLista<cDonante>* ListaDonantes = new cLista<cDonante>;
	cLista<cCentro>* ListaCentros = new cLista<cCentro>;
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

bool cINCUCAI::RecibirPaciente(cPaciente* paciente)
{
	if (paciente != NULL)
	{
		return true;
		IngresarPaciente(paciente);
	}
	return false;
}

bool cINCUCAI::IngresarPaciente(cPaciente* paciente)
{
	cDonante* donante_aux = dynamic_cast<cDonante*>(paciente);
	cReceptor* receptor_aux = dynamic_cast<cReceptor*>(paciente);
	if (donante_aux != NULL)
	{
		if (((*ListaDonantes) + donante_aux) == true)
		{
			BuscarPosiblesReceptores(donante_aux);
			return true;
		}
	}
	if (receptor_aux != NULL)
	{
		return (*ListaReceptores) + receptor_aux;
	}
	return false;
}

cLista<cReceptor>* cINCUCAI::BuscarPosiblesReceptores(cDonante* paciente) //agregar la desiguakdad a null y otras verificaciones 
{
	cLista<cReceptor>* sublistaReceptores = new cLista<cReceptor>;
	sublistaReceptores = ListaReceptores->ReceptoresCompatibles(paciente);
	if (sublistaReceptores != NULL)
	{
		ReceptorFinal(sublistaReceptores);
		return sublistaReceptores;
	}
	
}

cReceptor* cINCUCAI::ReceptorFinal(cLista<cReceptor>* listaReceptores)
{
	
}
