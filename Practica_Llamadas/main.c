#include <stdio.h>
#include <stdlib.h>
#include "personas.h"
#include "llamadas.h"
#define cant_personas 10
#define cant_llamadas 10

int main()
{
    sPersonas listaPersonas[cant_llamadas];
    inicializarPersonas(listaPersonas,cant_llamadas);
    hardcodearPersonas(listaPersonas,cant_llamadas);

    sLlamadas listaLlamadas[cant_llamadas];
    inicializarLlamadas(listaLlamadas,cant_llamadas);

    int opcion;
    do
    {
        printf("1.Hardcodear personas.\n2.Eliminar una persona.\n3.Modificar un numero de telefono.\n4.Alta de llamada.\n5.Mostrar Llamadas\n\n7.Salir.\n\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            agregarPersona(listaPersonas,cant_personas);
            break;
        case 2:
            eliminarPersona(listaPersonas,cant_personas);
            break;
        case 3:
            ModificarPersona(listaPersonas,cant_personas);
            break;
        case 4:
            agregarLlamadas(listaLlamadas,cant_llamadas,listaPersonas,cant_personas);
            break;
        case 5:
            mostrarTODASLASLLAMADAS(listaLlamadas,cant_llamadas);
        }
        system("pause");
        system("cls");
    }
    while(opcion!=7);

    return 0;
}
