#pragma once
#include "cVehiculo.h"
class cAmbulancia :
    public cVehiculo
{
    string tipo;
    string onomatopeya;
public:
    cAmbulancia(string _ID);
    ~cAmbulancia();
    string getOnomatopeya() { return onomatopeya; };
    void ImprimirDatos();
    string toString();
};

