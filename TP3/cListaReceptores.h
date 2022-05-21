#pragma once
#include "cReceptor.h"
#include <math.h>
using namespace std;
class cListaReceptores :
    public cLista<cReceptor>
{
public:
    cListaReceptores(int _max) :cLista(_max) {};
    ~cListaReceptores() {};
    cListaReceptores* ReceptoresCompatibles(cDonante* donante)
    {
        cListaReceptores* subLista = new cListaReceptores(TMAX);
        cLista<cOrgano>* ListaOrganos = donante->ListaOrganos;
        unsigned int i, j, cont = 0;
        for (i = 0; i < (donante->ListaOrganos->getCA()); i++) //recorre cada órgano del donante
        {
            for (j = 0; j < ca; j++) //ca es la cantidad actual de receptores
            {
                if ((*ListaOrganos)[i] == lista[j]->getOrgano() && (*lista[j]) == donante)//uso de sobrecarga == para ver si son compatibles

                {
                    cont++;
                    *subLista + lista[j]; //uso del operator +
                }
            }
        }
        for (unsigned int i = 0; i < cont; i++)
        {
            (*subLista)[i]->donanteAsignado = donante;
        }
        return subLista;
    };
    cReceptor* ReceptorDefinitivo()
    {
        cListaReceptores* listaaux3 = new cListaReceptores(ca); //tamaño máximo la cantidad de posiciones de la sublista
        cListaReceptores* listaaux2 = new cListaReceptores(ca);
        cListaReceptores* listaaux1 = new cListaReceptores(ca);
        cReceptor* receptorFinal = NULL;
        int counter3 = 0;
        int counter2 = 0;
        int counter1 = 0;
        if (lista != NULL)
        {
            for (unsigned int i = 0; i < ca; i++)
            {
                if (lista[i]->prioridad == 3)
                {
                    counter3++;
                    *listaaux3 + lista[i];
                }
                if (lista[i]->prioridad == 2)
                {
                    counter2++;
                    *listaaux2 + lista[i];
                }
                if (lista[i]->prioridad == 3)
                {
                    counter1++;
                    *listaaux1 + lista[i];
                }
            }

            if (counter3 == 1)
            {
                reSetDonanteAsignado((*listaaux3)[0]);
                receptorFinal = (*listaaux3)[0];
                delete listaaux3;
                return receptorFinal;
            }

            else if (counter3 > 1)
            {
                listaaux3->OrdenarPorFecha();
                reSetDonanteAsignado((*listaaux3)[0]);
                receptorFinal = (*listaaux3)[0];
                delete listaaux3;
                return receptorFinal;
            }
            if (counter2 == 1)
            {
                reSetDonanteAsignado((*listaaux2)[0]);
                receptorFinal = (*listaaux2)[0];
                delete listaaux2;
                return receptorFinal;
            }
            else if (counter2 > 1)
            {
                listaaux2->OrdenarPorFecha();
                reSetDonanteAsignado((*listaaux2)[0]);
                receptorFinal = (*listaaux2)[0];
                delete listaaux2;
                return receptorFinal;
            }
            if (counter1 == 1)
            {
                reSetDonanteAsignado((*listaaux1)[0]);
                receptorFinal = (*listaaux1)[0];
                delete listaaux1;
                return receptorFinal;
            }
            else if (counter1 > 1)
            {
                listaaux1->OrdenarPorFecha();
                reSetDonanteAsignado((*listaaux1)[0]);
                receptorFinal = (*listaaux1)[0];
                delete listaaux1;
                return receptorFinal;
            }
        }
        return NULL;
    };
    void reSetDonanteAsignado(cReceptor* receptor)
    {
        cDonante* donanteaux = receptor->donanteAsignado;
        for (unsigned int i = 0; i < ca; i++)
        {
            (*lista)[i].donanteAsignado = NULL;
        }
        receptor->donanteAsignado = donanteaux;
    };
    void OrdenarPorFecha()
    {
        unsigned int i, j = 0;
        cReceptor* aux = NULL;
        for (i = 0; i < ca - 1; i++)
        {
            int cont = 0;
            for (j = 0; j < ca - 1; j++)
            {
                if (((*lista)[j].fechaAgregacion) < ((*lista)[j + 1].fechaAgregacion))
                {
                    aux = lista[j];
                    lista[j] = lista[j + 1];
                    lista[j + 1] = aux;
                    cont++;
                }
            }
            if (cont == 0)
                break;
        }
    };
    cListaReceptores* BuscarPorOrgano(int numeroOrgano)
    {
        cListaReceptores* subLista = new cListaReceptores(ca);
        for (unsigned int i = 0; i < ca; i++)
        {
            subLista[i] = NULL;
        }
        for (unsigned int i = 0; i < ca; i++)
        {
            if (lista[i]->organo->getNumOrgano() == numeroOrgano)
            {
                (*subLista) + lista[i];
            }
        }
        return subLista;
    };
    cListaReceptores* BuscarPorCentro(cCentro* centro)
    {
        cListaReceptores* subLista = new cListaReceptores(ca);
        for (unsigned int i = 0; i < ca; i++)
        {
            subLista[i] = NULL;
        }
        for (unsigned int i = 0; i < ca; i++)
        {
            if (lista[i]->centroAsociado == centro)
            {
                (*subLista) + lista[i];
            }
        }
        return subLista;
    };
    int PrioridadEnLista(cReceptor* receptor)
    {
        if (receptor != NULL)
        {
            for (unsigned int i = 0; i < ca; i++)
            {
                if (lista[i] == receptor)
                    return lista[i]->prioridad;
            }
        }
    };
    void ImprimirLista()
    {
        for (unsigned int i = 0; i < ca; i++)
        {
            lista[i]->ImprimirDatos();
        }
    };
    friend ostream& operator<<(ostream& output, cReceptor& R) {
        output << " " << R.toString() << endl;
        return output;
    };
};



