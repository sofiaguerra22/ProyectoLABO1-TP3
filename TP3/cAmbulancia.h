#pragma once
#include "cVehiculo.h"
class cAmbulancia :
    public cVehiculo
{
    string onomatopeya;
    string ID;
public:
    cAmbulancia(string _ID);
    ~cAmbulancia();
};

