#pragma once
#include "cVehiculo.h"
class cAmbulancia :
    public cVehiculo
{
    string onomatopeya;
public:
    cAmbulancia(string _ID);
    ~cAmbulancia();
};

