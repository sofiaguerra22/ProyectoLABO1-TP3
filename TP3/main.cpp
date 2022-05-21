#pragma once
//#include <string>
#include <stdio.h>
#include <iostream>
#include "cINCUCAI.h"

using namespace std;

int main()
{
	cFecha* fechanac1 = new cFecha(27, 11, 2002);
	cFecha* fechanac2 = new cFecha(1, 4, 2002);
	cFecha* fechaAbla1 = new cFecha(23, 5, 2020);
	cFecha* fechaFall1 = new cFecha(20, 5, 2020);
	cOrgano* organo1 = new cOrgano(eOrgano::corazon);
	cCentro* centro1 = new cCentro("Fava", "Sar", "caba", "111", 1);
	cPaciente* paciente1 = new cPaciente("Eka", "2222",'f', eTipoSangre::ON, centro1, fechanac1,"123");
	cout << "" << paciente1->getProvincia() << endl;
	cReceptor* receptor1 = new cReceptor("Carla", "1234", 'f', eTipoSangre::ON, centro1, fechanac2, "1222", true, organo1);
	cout << "" << receptor1->getOrgano() << endl;
	cDonante* donante1 = new cDonante("Juan", "8988", 'm', eTipoSangre::ABN, centro1, fechanac2, "445556", fechaAbla1, fechaFall1);
	delete fechanac1;
	delete fechanac2;
	delete fechaAbla1;
	delete fechaFall1;
	delete centro1;
	delete paciente1;
	delete receptor1;
	delete donante1;
	system("pause");
}