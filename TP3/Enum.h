#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

enum class eOrgano {corazon, higado, pancreas, huesos,
	rinion, pulmones, intestino, piel, corneas};
enum class eTipoSangre {ON,OP,AN,AP,BN,BP,ABN,ABP};

string OrganoToString(eOrgano organo);
string TipoSangreToString(eTipoSangre sangre);
int OrganoToInt(eOrgano organo);


