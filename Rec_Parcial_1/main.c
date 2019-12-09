#include <stdio.h>
#include <stdlib.h>
#define CANT_NUM 10

/// Desarrollar 3 funciones: la primera recibirá un array de números enteros y
/// le pedirá al usuario que ingrese 10 números, que no podrán estar repetidos.
/// En caso de que el usuario intente ingresar 3 números repetidos la función
/// devolverá un valor que represente un error. La segunda función recibirá el
/// array del punto anterior y devolverá la suma de los números pares.
/// La ultima ordenará el array de enteros de manera creciente y mostrará el array ordenado.

void IngresarNumeros(int array[], int cant);
void MostrarNumeros(int lista[], int cant);
int SumaDeLosPares(int lista[], int cant);
void OrdenarAscendente(int lista[], int cant);

int main()
{
    int array2[CANT_NUM];
    printf("Ingrese 10 numeros (sin repetir):\n");
    IngresarNumeros(array2,CANT_NUM);
    printf("\n\nLista ordenada :\n");
    OrdenarAscendente(array2,CANT_NUM);
    MostrarNumeros(array2,CANT_NUM);

    printf("\nLa suma de los numeros pares es: %d\n",SumaDeLosPares(array2,CANT_NUM));

    return 0;
}

void IngresarNumeros(int array[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&array[i]);

        while(array[i]!=0 && array[i]==array[i-2])
        {
            printf("\nERROR.Ingrese un numero diferente: ");
            scanf("%d",&array[i]);
        }

        if(array[i] == array[i-2] || array[i] == array[i-3]|| array[i] == array[i-4]|| array[i] == array[i-5]|| array[i] == array[i-6]|| array[i] == array[i-7]|| array[i] == array[i-8]|| array[i] == array[i-9]|| array[i] == array[i-10])
        {
            printf("\nERROR!.se repitieron demasiados numeros\n");
            break;
        }
    }
    return array;
}

void MostrarNumeros(int lista[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        printf("numero :%d\n",lista[i]);
    }
}

int SumaDeLosPares(int lista[], int cant)
{
    int acumulador=0;
    int i;
    for(i=0; i<cant; i++)
    {
        if(lista[i]%2==0)
        {
            acumulador = acumulador + lista[i];
        }
    }
    return acumulador;
}

void OrdenarAscendente(int lista[], int cant)
{
    int aux;
    int i;
    int j;
    for(i=0; i<cant; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(lista[i]>lista[j])
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
    return lista;
}
