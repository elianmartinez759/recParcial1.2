#include "llamadas.h"
#include "personas.h"

int inicializarLlamadas(sLlamadas lista[], int cantidad)
{
    int ret = -1;
    int i;
    if(lista!=NULL && cantidad>0)
    {
        for(i=0; i<cantidad; i++)
        {
            lista[i].estaVacio = 1;
        }
        ret = 1;
    }
    return ret;
}

int buscarLLamadaVacia(sLlamadas lista[], int cantidad)
{
    int i;
    int index = -1;
    for(i=0; i<cantidad; i++)
    {
        if(lista[i].estaVacio == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

sLlamadas Pedir_Una_Llamada(sPersonas lista[], int cant)
{
    sLlamadas miLlamada;

    printf("Ingrese el Id de la persona que llama:");
    scanf("%d",&miLlamada.idPersona);
    fflush(stdin);
    while(EncontrarPersonaPorCodigo(lista,cant,miLlamada.idPersona)==-1)
    {
        printf("\nERROR.este codigo no existe!!!\nEscriba otro: \n\n");
        scanf("%d",&miLlamada.idPersona);
    }

    printf("\nIngrese el Id del destino de la llamada:");
    fflush(stdin);
    scanf("%d",&miLlamada.destino);
    while(EncontrarPersonaPorCodigo(lista,cant,miLlamada.destino)==-1)
    {
        printf("\nERROR.este codigo no existe!!!\nEscriba otro: \n\n");
        scanf("%d",&miLlamada.destino);
    }
    while(miLlamada.idPersona == miLlamada.destino)
    {
        printf("\nERROR.una persona no se puede llamar a si misma!!!\nEscriba otro id para el destino: \n\n");
        scanf("%d",&miLlamada.destino);
    }

    printf("\nIngrese el tipo de llamada: \n\n1 = larga distancia.\n2 = corta distancia.\n");
    fflush(stdin);
    scanf("%d",&miLlamada.tipo);

    printf("\nIngrese el estado de la llamada: \n\n1 = en curso.\n2 = terminado.\n3 = no se pudo conectar.\n");
    fflush(stdin);
    scanf("%d",&miLlamada.estado);

    return miLlamada;
}

int agregarLlamadas(sLlamadas lista[], int cantidad, sPersonas listaPer[], int cantPer)
{
    int indice;

    indice = buscarLLamadaVacia(lista,cantidad);

    if(indice!=-1)
    {
        lista[indice] = Pedir_Una_Llamada(listaPer,cantPer);
        lista[indice].idLLAMADA = indice + 1;
    }
    return indice;
}

void mostrarUNALLAMADA(sLlamadas unaLlamada)
{
    if(unaLlamada.estaVacio!=1)
    {
        printf("\n%d -- %d -- %d -- %d -- %d\n",unaLlamada.idLLAMADA, unaLlamada.idPersona,unaLlamada.destino,unaLlamada.estado,unaLlamada.tipo);
    }
}

void mostrarTODASLASLLAMADAS(sLlamadas lista[], int cantidad)
{
    int i;
    printf("\nID -- IDPER -- DESTINO -- ESTADO -- TIPO\n");
    for(i=0; i<cantidad; i++)
    {
        mostrarUNALLAMADA(lista[i]);
    }
}






