#pragma once
//#include <string>
#include <stdio.h>
#include <iostream>
#include "cINCUCAI.h"

using namespace std;

int main()
{
	//fechas
	//nacimientos
	cFecha* fechanac1 = new cFecha(27, 11, 2002);
	cFecha* fechanac2 = new cFecha(1, 4, 2002);
	cFecha* fechanac3 = new cFecha(4, 6, 1996);
	cFecha* fechanac4 = new cFecha(14, 4, 2006);
	//ablacion y fallecimiento
	cFecha* fechaFall1 = new cFecha(20, 5, 2022);
	cFecha* fechaFall2 = new cFecha(20, 5, 2022);


	//organos
	cOrgano* organo1 = new cOrgano(eOrgano::corazon);
	cOrgano* organo2 = new cOrgano(eOrgano::higado);
	cOrgano* organo3 = new cOrgano(eOrgano::huesos);

	//centros
	cCentro* centro1 = new cCentro("Fava", "Sarmiento 1564", "caba", "111", 1);
	cCentro* centro2 = new cCentro("Davila", "StaRosa 987", "Amba", "123", 2);//distinta provincia y partido que c1
	cCentro* centro3 = new cCentro("Italiano", "Solis 456", "caba", "123", 3);//misma provincia y != partido que c1
	
	//listas
	cLista<cOrgano>* listaOrganosDon1 = new cLista<cOrgano>;

	//INCUCAI
	cINCUCAI* INCUCAI = new cINCUCAI();



	//codigo
	cPaciente* paciente1 = new cPaciente("Eka", "2222",'f', eTipoSangre::ON, centro1, fechanac1,"123");
	cout << "" << paciente1->getProvincia() << endl;
	cReceptor* receptor1 = new cReceptor("Carla", "1234", 'f', eTipoSangre::ON, centro1, fechanac2, "1222", true, organo1);//receptor joven y estable
	//receptor1->ImprimirDatos();
	cReceptor* receptor2 = new cReceptor("Federico", "3321", 'm', eTipoSangre::ABN, centro1, fechanac3, "3456", false, organo2);//receptor mayor e inestable
	//receptor2->ImprimirDatos();
	cReceptor* receptor3 = new cReceptor("Juana", "2234", 'f', eTipoSangre::ON, centro2, fechanac4, "4582", false, organo3);//receptor joven e inestable
	//receptor3->ImprimirDatos();
	cDonante* donante1 = new cDonante("Juan", "8988", 'm', eTipoSangre::ABN, centro2, fechanac2, "445556",fechaFall1);
	//le asigno organos que puede donar el donante
	*listaOrganosDon1 + organo1;
	*listaOrganosDon1 + organo2;
	donante1->setListaOrganos(listaOrganosDon1);
	donante1->ImprimirDatos();

	INCUCAI->RecibirPaciente(receptor1);
	INCUCAI->RecibirPaciente(receptor2);
	INCUCAI->RecibirPaciente(receptor3);
	INCUCAI->RecibirPaciente(donante1);




	delete organo1;
	delete organo2;
	delete organo3;
	delete fechanac1;
	delete fechanac2;
	delete fechanac3;
	delete fechanac4;
	delete fechaFall1;
	delete centro1;
	delete centro2;
	delete centro3;
	delete paciente1;
	delete receptor1;
	delete receptor2;
	delete receptor3;
	delete donante1;
	system("pause");
}