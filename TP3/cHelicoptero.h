#pragma once
#include "cVehiculo.h"
class cHelicoptero :
    public cVehiculo
{
    string onomatopeya;
public:
    cHelicoptero(string _ID);
    ~cHelicoptero();
};

