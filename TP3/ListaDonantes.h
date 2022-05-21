#pragma once
#include "cDonante.h"
#include <math.h>
using namespace std;
class cListaDonantes :
    public cLista<cDonante>
{
public:
    cListaDonantes(int _max) :cLista(_max) {};
    ~cListaDonantes() {};

    void ImprimirLista()
    {
        for (int i = 0; i < ca; i++)
        {
            lista[i]->ImprimirDatos();
        }
    };
    friend ostream& operator<<(ostream& output, cDonante& D) {
        output << " " << D.toString() << endl;
        return output;
    };
};