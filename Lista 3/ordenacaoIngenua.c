#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// faz a leitura dos n números
void le_array (int *t, int *array)
{
    int i = 0;
    for (int *pi = &i; *pi < *t; (*pi)++)
    {
        scanf ("%d", (array+*pi));
    }
}

// ordena o array passado como parâmentro
void insertion_ (int *tam, int *array)
{
    int i = 1, k, j;
    int *pi, *pk = &k, *pj = &j;

    for (pi = &i; *pi < *tam; (*pi)++){
        *pk = *(array+*pi);
        *pj = *pi - 1;
        while (*pj >= 0 && *(array+*pj) > *pk) {
                *(array+*pj + 1) = *(array+*pj);
                *pj = *pj - 1;
            }
        *(array+*pj + 1) = *pk;
        }
}


void imprime_ (int *t, int *array)
{
    int i = 0;
    for (int *pi = &i; *pi < *t; (*pi)++)
        printf("[%d]", *(array+*pi));
    printf ("\n");

}

int main ()
{

    int t;
    scanf ("%d", &t);
    int array[t];

    le_array ( &t, array );

    insertion_ ( &t , array );

    imprime_ ( &t, array );





    return 0;
}
