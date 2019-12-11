#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piloto.h"
#include "destino.h"
#include <ctype.h>

typedef struct
{
    int idVuelo;
    int idDestino;
    int idPiloto;
    int partida;
    int llegada;
    char EstadoVuelo[31];
    int estaVacio;
}sVuelos;

int inicializarVuelos(sVuelos lista[], int cant);
int buscarEspacioVuelos(sVuelos lista[], int cant);
