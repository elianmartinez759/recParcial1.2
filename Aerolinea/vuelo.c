#include "vuelo.h"

int inicializarVuelos(sVuelos lista[], int cant)
{
    int i;
    int ret = -1;
    if(lista!=NULL && cant>0)
    {
        for(i=0; i<cant; i++)
        {
            lista[i].estaVacio = 1;
        }
        ret = 1;
    }
    return ret;
}

int buscarVUELo(sVuelos lista[], int cant, int codigo)
{
    int i;
    int index = -1;
    for(i=0; i<cant; i++)
    {
        if(lista[i].idVuelo == codigo)
        {
            index = i;
        }
    }
    return index;
}

int buscarEspacioVuelos(sVuelos lista[], int cant)
{
    int i;
    int index = -1;
    for(i=0; i<cant; i++)
    {
        if(lista[i].estaVacio == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

sVuelos Pedir_Vuelo(sPilotos listaP[], int cantP, sDestinos listaDest[], int cantDest)
{
    int estado;
    sVuelos miVuelo;
    printf("\nIngrese id del Destino\n");
    mostrarTODOSlosDestinos(listaDest,cantDest);
    scanf("%d",&miVuelo.idDestino);
    while(buscarDestinoPorCodigo(listaDest,cantDest,miVuelo.idDestino)==-1)
    {
        printf("\nEste destino no existe, ingrese otro: \n");
        scanf("%d",&miVuelo.idDestino);
    }
    printf("\nIngrese id del Piloto\n");
    mostrarListaPilotos(listaP,cantP);
    scanf("%d",&miVuelo.idPiloto);
    while(buscarPilotoPorCodigo(listaP,cantP,miVuelo.idPiloto)==-1)
    {
        printf("\nEste piloto no existe, ingrese otro: \n");
        scanf("%d",&miVuelo.idPiloto);
    }

    printf("\nIngrese hora de partida: \n");
    scanf("%d",&miVuelo.partida);
    /*while(miVuelo.partida <0 || miVuelo.partida>24);
    {
        printf("\nHora de partida invalida, ingrese otra: \n");
        scanf("%d",&miVuelo.partida);
    }*/

    printf("\nIgrese hora de llegada: ");
    scanf("%d",&miVuelo.llegada);
    /*while(miVuelo.llegada<0 || miVuelo.llegada>24);
    {
        printf("\nHora de llegada invalida, ingrese otra: \n");
        scanf("%d",&miVuelo.llegada);
    }*/

    while(miVuelo.partida == miVuelo.llegada) /// si son iguales
    {
        printf("\nHora de llegada invalida, ingrese otra hora de llegada: \n");
        scanf("%d",&miVuelo.llegada);
    }

    printf("\nIngrese estado del vuelo: 1 activo, 2 suspendido, 3 demorado o 4 cancelado.\n");

    scanf("%d",&estado);
    switch(estado)
    {
    case 1:
        strcpy(miVuelo.EstadoVuelo,"activo");
        break;
    case 2:
        strcpy(miVuelo.EstadoVuelo,"suspendido");
        break;
    case 3:
        strcpy(miVuelo.EstadoVuelo,"demorado");
        break;
    case 4:
        strcpy(miVuelo.EstadoVuelo,"cancelado");
    default :
        printf("\nOpcion no valida!\n");
        break;
    }

    printf("\n\nVuelo cargado.\n");

    return miVuelo;
}

int agregarVuelo(sVuelos lista[], int cant, sPilotos listaPilotos[], int cantPil, sDestinos listaDestinos[], int cantDest)
{
    int indice;
    indice = buscarEspacioVuelos(lista,cant);
    if(indice!=-1)
    {
        lista[indice] = Pedir_Vuelo(listaPilotos,cantPil,listaDestinos,cantDest);
        lista[indice].idVuelo = indice+1;
        lista[indice].estaVacio = 0;
    }
    return indice;
}

void MostrarUNvuelo(sVuelos unVuelo)
{
    if(unVuelo.estaVacio!=1)
    {
        printf("%d     %d       %d       %d       %d    %s\n",unVuelo.idVuelo,unVuelo.idDestino,unVuelo.idPiloto,unVuelo.partida,unVuelo.llegada,unVuelo.EstadoVuelo);
    }
}

void MostrarTODOSLOSvuelos(sVuelos lista[], int cant)
{
    int i;
    printf("\nID  idDest  idPil  HoraPar  HoraLleg       Estado\n");
    for(i=0; i<cant; i++)
    {
        MostrarUNvuelo(lista[i]);
    }
}


void eliminarVuelo(sVuelos lista[], int cant)
{
    int codigo;
    int index;
    int baja;
    printf("\nIngrese el codigo del vuelo: ");
    MostrarTODOSLOSvuelos(lista,cant);
    scanf("%d",&codigo);

    index = buscarVUELo(lista,cant,codigo);
    if(index!=-1)
    {
        printf("\nSeguro que quiere eliminar este vuelo: \n1: Si.\n2: No.\n\n");
        printf("\nID  idDest  idPil  HoraPar  HoraLleg       Estado\n");

        MostrarUNvuelo(lista[index]);
        scanf("%d",&baja);
        switch(baja)
        {
        case 1:
            lista[index].estaVacio = 1;
            printf("\nEliminado con exito.\n");
            break;
        case 2:
            printf("\nCancelado.\n");
            break;
        default:
            printf("\nOpcion no valida.\n");
            break;
        }
    }
    else
    {
        printf("\nCodigo no existe\n");
    }
}

void CambiarEstado(sVuelos lista[], int cant)
{
    int estado;
    int codigo;
    int index;
    int baja;
    printf("\nIngrese el codigo del vuelo: ");
    MostrarTODOSLOSvuelos(lista,cant);
    scanf("%d",&codigo);

    index = buscarVUELo(lista,cant,codigo);
    if(index!=-1)
    {
        printf("\nSeguro que quiere cambiar el estado de este vuelo: \n1: Si.\n2: No.\n\n");
        printf("\nID  idDest  idPil  HoraPar  HoraLleg       Estado\n");

        MostrarUNvuelo(lista[index]);
        scanf("%d",&baja);
        switch(baja)
        {
        case 1:

            printf("\nIngrese estado del vuelo: 1 activo, 2 suspendido, 3 demorado o 4 cancelado.\n");

            scanf("%d",&estado);
            switch(estado)
            {
            case 1:
                strcpy(lista[index].EstadoVuelo,"activo");
                break;
            case 2:
                strcpy(lista[index].EstadoVuelo,"suspendido");
                break;
            case 3:
                strcpy(lista[index].EstadoVuelo,"demorado");
                break;
            case 4:
                strcpy(lista[index].EstadoVuelo,"cancelado");
            default :
                printf("\nOpcion no valida!\n");
                break;
            }
            break;
        case 2:
            printf("\nCancelado.\n");
            break;
        default:
            printf("\nOpcion no valida.\n");
            break;
        }
    }
    else
    {
        printf("\nCodigo no existe\n");
    }
}

void listarVuelosPorPiloto(sVuelos lista[], int cant, sPilotos listaP[], int cantP)
{
    int idDElpiloto;
    printf("\nIngrese codigo del piloto: \n");
    mostrarListaPilotos(listaP,cantP);
    scanf("%d",&idDElpiloto);
    int i;

    printf("\nVuelos: \n\n");
    printf("\nID  idDest  idPil  HoraPar  HoraLleg       Estado\n");
    for(i=0; i<cant; i++)
    {
        if(lista[i].idPiloto == idDElpiloto)
        {
            MostrarUNvuelo(lista[i]);
        }
    }
}

void ListaPilotosQueVolaronA(sVuelos lista[], int cant, sPilotos listaP[], int cantP, sDestinos listaDest[], int cantDest)
{
    int idDelDestino;
    printf("\nIngrese id del destino: \n");
    mostrarTODOSlosDestinos(listaDest,cantDest);
    scanf("%d",&idDelDestino);

    int i;

    printf("\nPilotos que volaron a este destino: \n\n");
    printf("\nID\tNOMBRE\n");
    //printf("\nID  idDest  idPil  HoraPar  HoraLleg       Estado\n");
    for(i=0; i<cant; i++)
    {
        if(lista[i].idDestino == idDelDestino)
        {
            mostrarPiloto(lista[i].idPiloto);
        }
    }

}

void ListarLosVuelos(sVuelos lista[], int cant, sPilotos listaP[], int cantP, sDestinos listaDest[], int cantDest)
{
    char nombreP[10];
    char destinoP[10];
    int i;
    int idP;
    int idD;
    for(i=0; i<cant; i++)
    {
        if(lista[i].estaVacio != 1)
        {
            idP = lista[i].idPiloto;
            idD = lista[i].idDestino;

            switch(idP)
            {
            case 1:
                strcpy(nombreP,"elian");
                break;
            case 2:
                strcpy(nombreP,"pedro");
                break;
            case 3:
                strcpy(nombreP,"carlos");
                break;
            }

            switch()

            printf("%d\t %s\t %s\n",lista[i].idVuelo,nombreP,);
        }
    }
}



