#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
#include "cLista.h"
#include "cPaciente.h"
#include "cReceptor.h" //CONSULTAR
#include "cDonante.h"
#include "cCentroSalud.h"
using namespace std;
class cINCUCAI
{
	cLista<cReceptor>* ListaReceptores;
	cLista<cDonante>* ListaDonantes;
	cLista<cCentroSalud>* ListaCentros;

public:
	cINCUCAI();
	~cINCUCAI();
	//RecibirPaciente(cDonante* donante); LLAMA A INGRESAR PACIENTE
	//IngresarPaciente(); LLAMA A BUSCAR POSIBLES RECEPTORES
	//cLista<cReceptor>* BuscarPosiblesReceptores(); LLAMA A RECEPTOR FINAL
	//cReceptor* ReceptorFinal(); LLAMA A PROTOCOLO 
	//ProtocoloTransporteTrasplante();

};

