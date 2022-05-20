#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
#include "cLista.h"
#include "cListaReceptores.h"
#include "cPaciente.h"
#include "cReceptor.h" 
#include "cDonante.h"
#include "cCentro.h"
using namespace std;
class cINCUCAI
{
	cListaReceptores* ListaReceptores;
	cLista<cDonante>* ListaDonantes;
	cLista<cCentro>* ListaCentros;

public:
	cINCUCAI();
	~cINCUCAI();
	bool RecibirPaciente(cPaciente* paciente); 
	bool IngresarPaciente(cPaciente* paciente); 
	cLista<cReceptor>* BuscarPosiblesReceptores(cDonante* paciente);//LLAMA A RECEPTOR FINAL
	cReceptor* ReceptorFinal(cLista<cReceptor>* listaReceptores); //LLAMA A PROTOCOLO 
	//ProtocoloTransporteTrasplante();

};

