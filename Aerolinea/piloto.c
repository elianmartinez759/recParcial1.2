#include "piloto.h"
int buscarPilotoPorCodigo(sPilotos lista[], int cant, int codigo)
{
    int retorno = -1;
    int i;
    for(i=0; i<cant; i++)
    {
        if(lista[i].id == codigo)
        {
            retorno = i;
        }
    }

    return  retorno;
}

void hardcodearPilotos(sPilotos lista[], int cant)
{
    int i;
    int ids[] = {1,2,3,};
    char nombres[][31] = {"elian","pedro","carlos"};

    for(i=0; i<cant; i++)
    {
        lista[i].id = ids[i];
        strcpy(lista[i].nombre,nombres[i]);
    }
}

void mostrarPiloto(sPilotos unPiloto)
{
    printf("%d\t%s\n",unPiloto.id,unPiloto.nombre);
}

void mostrarListaPilotos(sPilotos lista[], int cant)
{
    int i;
    printf("\nID\tNOMBRE\n");
    for(i=0; i<cant; i++)
    {
        mostrarPiloto(lista[i]);
    }
}
