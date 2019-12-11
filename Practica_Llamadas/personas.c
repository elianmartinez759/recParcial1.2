#include "personas.h"

int inicializarPersonas(sPersonas lista[], int cant)
{
    int ret = -1;
    int i;
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

int buscarPersonaVacia(sPersonas lista[], int cant)
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

sPersonas Perdir_Persona()
{
    sPersonas miPersona;

    printf("\nIngrese el telefono de la persona: ");
    scanf("%d", &miPersona.telefono);
    fflush(stdin);

    printf("\nIngrese el nombre de la persona: ");
    gets(miPersona.nombre);

    printf("\nPersona ingresada.\n");

    return miPersona;
}

int agregarPersona(sPersonas lista[], int cant)
{
    int indice;

    indice = buscarPersonaVacia(lista,cant);

    if(indice!=-1)
    {
        lista[indice] = Perdir_Persona();
        lista[indice].id = indice + 1;
        lista[indice].estaVacio = 0;
    }
    else
    {
        printf("\nNo hay mas espacio.\n");
    }
    return indice;
}

void mostrarUNApersona(sPersonas unaPersona)
{
    if(unaPersona.estaVacio!=1)
    {
        printf("%d\t%s\t%d\n",unaPersona.id,unaPersona.nombre,unaPersona.telefono);
    }
}

void mostrarTODASlasPersonas(sPersonas lista[], int cant)
{
    printf("\nID\tNOMBRE\tTELEFONO\n");
    int i;
    for(i=0; i<cant; i++)
    {
        mostrarUNApersona(lista[i]);
    }
}

void hardcodearPersonas(sPersonas lista[], int cant)
{
    int i;
    int indice;
    int numeros[] = {1234,4444,777,9876};
    char nombres[][51] = {"Elian","Juana","Carlos","Pedro"};
    indice = buscarPersonaVacia(lista,cant);
    for(i=indice; i<indice+4; i++)
    {
        lista[i].telefono = numeros[i];
        strcpy(lista[i].nombre,nombres[i]);
        lista[i].id = i + 1;
        lista[i].estaVacio = 0;
    }
    printf("\nPersonas Hardcodeadas.\n\n");
}

int EncontrarPersonaPorCodigo(sPersonas lista[], int cant, int codigo)
{
    int i;
    int retorno = -1;
    for(i=0; i<cant; i++)
    {
        if(lista[i].id == codigo)
        {
            retorno = i;
        }
    }
    return retorno;
}

void eliminarPersona(sPersonas lista[], int cant)
{
    int codigo;
    int index;
    int baja;
    printf("\nIngrese el codigo de la persona: ");
    mostrarTODASlasPersonas(lista,cant);
    scanf("\n%d",&codigo);

    index = EncontrarPersonaPorCodigo(lista,cant,codigo);

    if(index!=-1)
    {
        printf("\n----------------------------------------\n\nSeguro que quiere eliminar esta persona: \n");
        mostrarUNApersona(lista[index]);
        printf("\n1 = SI.\n\n2 = NO.\n");
        scanf("\n%d",&baja);

        switch(baja)
        {
        case 1:
            lista[index].estaVacio = 1;
            break;
        case 2:
            printf("\nCancelado.\n\n");
            break;
        default :
            printf("\nOpcion no valida!\n\n");
            break;
        }
    }
    else
    {
        printf("\nEsta persona no existe\n");
    }
}

void ModificarPersona(sPersonas lista[], int cant)
{
    int codigo;
    int index;
    int cambiar;
    int nuevoNumero;

    printf("\nIngrese el codigo de la persona: ");
    mostrarTODASlasPersonas(lista,cant);
    scanf("\n%d",&codigo);

    index = EncontrarPersonaPorCodigo(lista,cant,codigo);

    if(index!=-1)
    {
        mostrarUNApersona(lista[index]);
        printf("\nIngrese el nuevo numero: \n");
        scanf("%d",&nuevoNumero);
        printf("\nSeguro quiere cambiar el numero: \n\n1 = SI.\n\n2 = NO\n");
        scanf("\n%d",&cambiar);

        switch(cambiar)
        {
        case 1:
            lista[index].telefono = nuevoNumero;
            break;
        case 2:
            printf("\nCancelado.\n\n");
            break;
        default :
            printf("\nOpcion no valida!\n\n");
            break;
        }
    }
    else
    {
        printf("\nEsta persona no existe\n");
    }
}

