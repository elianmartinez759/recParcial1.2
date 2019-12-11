#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[41];
    int telefono;
    int estaVacio;
}sPersonas;

int inicializarPersonas(sPersonas lista[], int cant);
int buscarPersonaVacia(sPersonas lista[], int cant);
int buscarPersonaVacia(sPersonas lista[], int cant);

sPersonas Perdir_Persona();
int agregarPersona(sPersonas lista[], int cant);

void mostrarUNApersona(sPersonas unaPersona);
void mostrarTODASlasPersonas(sPersonas lista[], int cant);

void hardcodearPersonas(sPersonas lista[], int cant);

int EncontrarPersonaPorCodigo(sPersonas lista[], int cant, int codigo);
void eliminarPersona(sPersonas lista[], int cant);
void ModificarPersona(sPersonas lista[], int cant);





