#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
#include "cListaReceptores.h"
#include "cPaciente.h"
#include <math.h>
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
	cListaReceptores* BuscarPosiblesReceptores(cDonante* paciente);//LLAMA A RECEPTOR FINAL
	cReceptor* ReceptorFinal(cListaReceptores* sublistaReceptores); //LLAMA A PROTOCOLO 
	bool ProtocoloTransporteTrasplante(cReceptor* receptor);
	void ResultadoTransplante(bool exito, cReceptor* receptor);
};

