#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int* le_array (int *t)
{
    int *v = malloc ((*t) * sizeof(int));
    int i = 0;
    for (int *pi = &i; *pi < *t; (*pi)++)
    {
        scanf ("%d", (v+*pi));
    }
    return v;
}

int* copia_array (int *t, int *vet)
{
    int *v = malloc ((*t) * sizeof(int));
    int i = 0;
    for (int *pi = &i; *pi < *t; (*pi)++)
    {
        *(v+*pi) = *(vet+*pi);
    }
    return v;
}

void insertion_ (int *tam, int *array)
{
    int i = 1, k, j;
    int *pi, *pk = &k, *pj = &j;
    for (int *pi = &i; *pi < *tam; (*pi)++){
        *pk = *pi - 1;
        *pj = *pi;
        while (*pk >= 0) {
            if (*(array+*pj) < *(array+*pk)) {
                int aux = *(array+*pj);
                *(array+*pj) = *(array+*pk);
                *(array+*pk) = aux;
                k--;
                j--;
            } else {
                break;
            }
        }
    }
}

void imprime_ (int *t, int *vet, int *vOriginal)
{
    // ordem Ambrosio, Peu, Minerin, Entidade, Jeff.
    char vetNome[5][10] = {"Ambrosio", "Peu", "Minerin", "Entidade", "Jeff"};

    int j;
    int *pj = &j;

    for (*pj = 0; *pj < *t; (*pj)++) { if (*(vet+1) == *(vOriginal+*pj)) { printf ("Terca-feira: %s\n", *(vetNome+*pj)); }}
    for (*pj = 0; *pj < *t; (*pj)++) { if (*(vet+2) == *(vOriginal+*pj)) { printf ("Quarta-feira: %s\n", *(vetNome+*pj)); }}
    for (*pj = 0; *pj < *t; (*pj)++) { if (*(vet+3) == *(vOriginal+*pj)) { printf ("Quinta-feira: %s\n", *(vetNome+*pj)); }}
    for (*pj = 0; *pj < *t; (*pj)++) { if (*(vet+4) == *(vOriginal+*pj)) { printf ("Sexta-feira: %s\n", *(vetNome+*pj));  }}
}

int main ()
{

    int t = 5;
    // lê tempo gasto por cada um
    int *vet = le_array( &t );
    // faz uma cópia antes de ordenar para manter a ordem em que foi lido
    int *vOriginal = copia_array ( &t, vet );

    // ordena do menor para o maior tempo
    insertion_ ( &t , vet );

    // imprime o resultado
    imprime_ ( &t, vet, vOriginal );


    return 0;
}
