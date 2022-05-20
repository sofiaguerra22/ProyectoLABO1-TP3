#pragma once
#include "cVehiculo.h"
class cAvion :
    public cVehiculo
{
    string tipo;
    string onomatopeya;
public:
    cAvion(string _ID);
    ~cAvion();
    string getOnomatopeya() { return onomatopeya; };
};

