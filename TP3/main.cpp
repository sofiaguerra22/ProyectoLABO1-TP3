#pragma once
//#include <string>
#include <stdio.h>
#include <iostream>
#include "cINCUCAI.h"

using namespace std;

int main()
{
	cFecha* fechanac1 = new cFecha(27, 11, 2002);
	cCentro* centro1 = new cCentro("Fava", "Sar", "caba", "111", 1);
	cPaciente* paciente1 = new cPaciente("Eka", "2222",'f', eTipoSangre::ON, centro1, fechanac1);
	cout << "" << paciente1->getProvincia() << endl;
	delete fechanac1;
	delete centro1;
	delete paciente1;
	system("pause");
}