#include "destino.h"

int buscarDestinoPorCodigo(sDestinos lista[], int cant, int codigo)
{
    int retorno = -1;
    int i;
    for(i=0; i<cant; i++)
    {
        if(lista[i].idDest == codigo)
        {
            retorno = i;
        }
    }

    return  retorno;
}

void hardcodearDestinos(sDestinos lista[], int cant)
{
    int i;
    int idDestinos[] = {1,2,3,4};
    char descripcionDest[][31] = {"Cancun","Miami","Rio","Dominicana"};
    int precios[] = {10,20,30,40};

    for(i=0; i<cant; i++)
    {
        lista[i].idDest = idDestinos[i];
        strcpy(lista[i].descripcion,descripcionDest[i]);
        lista[i].precio = precios[i];
    }
}

void mostrarUNdestino(sDestinos unDestino)
{
    printf("%d\t%s\t%d\n",unDestino.idDest,unDestino.descripcion,unDestino.precio);
}

void mostrarTODOSlosDestinos(sDestinos lista[], int cant)
{
    int i;
    printf("\nID\tDESC\tPRECIO\n");
    if(lista!=NULL && cant>0)
    {
        for(i=0; i<cant; i++)
        {
            mostrarUNdestino(lista[i]);
        }
    }
}
