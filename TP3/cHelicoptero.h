#pragma once
#include "cVehiculo.h"
class cHelicoptero :
    public cVehiculo
{
    string tipo;
    string onomatopeya;
public:
    cHelicoptero(string _ID);
    ~cHelicoptero();
    string getOnomatopeya() { return onomatopeya; };
    void ImprimirDatos();
    string toString();
};

