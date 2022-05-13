#pragma once
#include "cVehiculo.h"
class cAvion :
    public cVehiculo
{
    string onomatopeya;
    string ID;
public:
    cAvion(string _ID);
    ~cAvion();
};

