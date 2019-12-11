#include <stdio.h>
#include <stdlib.h>
#include "vuelo.h"


int main()
{
    sVuelos listaVuelos[10];
    sPilotos listaPilotos[3];
    sDestinos listaDestinos[4];
    hardcodearDestinos(listaDestinos,4);
    hardcodearPilotos(listaPilotos,3);
    inicializarVuelos(listaVuelos,10);

    int opcion;

    do
    {


    printf("1.Alta Vuelo.\n2.Baja Vuelo.\n3.Modificacion Estado.\n5.Listar vuelos por piloto\n7.Salir.\n");
    scanf("%d",&opcion);
    switch(opcion)
    {
    case 1:
        agregarVuelo(listaVuelos,10,listaPilotos,3,listaDestinos,4);
        break;
    case 2:
        eliminarVuelo(listaVuelos,10);
        break;
    case 3:
        CambiarEstado(listaVuelos,10);
        break;
    case 4:
        //MostrarTODOSLOSvuelos(listaVuelos,10);
        ListarLosVuelos(listaVuelos,10,listaPilotos,3,listaDestinos,4);
        break;
    case 5:
        listarVuelosPorPiloto(listaVuelos,10,listaPilotos,3);
        break;
    case 6:
        ListaPilotosQueVolaronA(listaVuelos,10,listaPilotos,3,listaDestinos,4);
        break;
    }
    system("pause");
    system("cls");

    }while(opcion!=7);



    return 0;
}
