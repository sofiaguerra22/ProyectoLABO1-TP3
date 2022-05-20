#pragma once
#include "cVehiculo.h"
class cAvion :
    public cVehiculo
{
    string onomatopeya;
public:
    cAvion(string _ID);
    ~cAvion();
};

