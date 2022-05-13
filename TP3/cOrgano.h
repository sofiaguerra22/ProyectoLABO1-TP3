#pragma once
#include <string>
#include <iostream>
#include "Enum.h"
#include <ctime>
using namespace std;
class cOrgano
{
	eOrgano organo;
	//fecha CONSULTAR
public:
	cOrgano(eOrgano _organo);
	~cOrgano();
	int getNumOrgano() { return OrganoToInt(organo); };
};

