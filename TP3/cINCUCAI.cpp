#include "cINCUCAI.h"

cINCUCAI::cINCUCAI()
{
	this->ListaReceptores = new cListaReceptores(TMAX);
	this->ListaDonantes = new cLista<cDonante>;
	this->ListaCentros = new cLista<cCentro>;
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
		if (((*ListaReceptores) + receptor_aux) == true)
			return true;
	}
	return false;
}

cListaReceptores* cINCUCAI::BuscarPosiblesReceptores(cDonante* paciente) //agregar la desiguakdad a null y otras verificaciones 
{
	cListaReceptores* sublistaReceptores = new cListaReceptores(TMAX);
	sublistaReceptores = ListaReceptores->ReceptoresCompatibles(paciente);
	if (sublistaReceptores != NULL)
	{
		ReceptorFinal(sublistaReceptores);
		return sublistaReceptores;
	}
	return NULL;
	
}

cReceptor* cINCUCAI::ReceptorFinal(cListaReceptores* sublistaReceptores)
{
	cReceptor* receptorFinal = sublistaReceptores->ReceptorDefinitivo();
	if (receptorFinal != NULL)
	{
		ProtocoloTransporteTrasplante(receptorFinal);
		delete sublistaReceptores;
		return receptorFinal;
	}
	return NULL;
}


bool cINCUCAI::ProtocoloTransporteTrasplante(cReceptor* receptor) //ver de cambiar a void
{
	cCentro* centroReceptor = receptor->getCentro();
	cDonante* donanteAsignado = receptor->getDonante();
	cCentro* centroDonante = donanteAsignado->getCentro();
	cOrgano* organoAdonar = receptor->getOrgano();
	cVehiculo* vehiculoAsigando = centroReceptor->AsignarVehiculo(donanteAsignado, receptor);
	if (vehiculoAsigando != NULL)
	{
		if (centroReceptor->IniciarAblacion(receptor, organoAdonar, vehiculoAsigando) == true)
		{
			if (centroDonante->RealizarTransporte(vehiculoAsigando, receptor) == true)
			{
				ResultadoTransplante((centroReceptor->RealizarTrasplante(receptor)),receptor);
			}
		}
	}
	return false;
}

void cINCUCAI::ResultadoTransplante(bool exito, cReceptor* receptor)
{
	if (exito == true)
	{
		(*ListaReceptores) - receptor;
	}
	else if (exito == false)
	{
		receptor->prioridad = 3;
		receptor->estado = false;
	}
}
