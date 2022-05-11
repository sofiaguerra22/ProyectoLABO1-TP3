#pragma once
#include "cVehiculo.h"
class cHelicoptero :
    public cVehiculo
{
    string onomatopeya;
    string ID;
public:
    cHelicoptero(string _ID);
    ~cHelicoptero();
};

