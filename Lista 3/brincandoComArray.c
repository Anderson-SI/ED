#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// ordena o array e imprime
void ordenacao (int *tam, int *array)
{
    int i = 0, f = 0, j, x;
    int *pj = &j;
    int *px = &x;

    for (int *pi = &i; *pi < (*tam) - 1; (*pi)++) {
        for (*pj = *pi + 1; *pj < (*tam); (*pj)++) {
                if (*(array+(*pi)) < *(array+(*pj))) {
                    *px = *(array+(*pi));
                    *(array+(*pi)) = *(array+(*pj));
                    *(array+(*pj)) = *px;
                }
        }
    }
    // imprime o array
    for (int *pf = &f; *pf < *tam - 1; (*pf)++){
        printf ("%d ", *(array+*pf));
    }
    printf ("%d\n", *(array + ((*tam) - 1)));
}

// faz o deslocamento para a esquerda
void desloca (int *tam, int *array)
{
    int i = 1;
    for (int *pi = &i; *pi < *tam; (*pi)++) {
        printf ("%d ", *(array+*pi));
    }
    printf ("%d\n", *(array));
}

// imprime de forma inversa
void imprime_inversa (int *tam, int *array)
{
    if (*tam == 1) {
        printf ("%d\n", *(array));
        return;
    } else {
        *tam = *tam - 1;
        printf ("%d ", *(array + *tam));
        imprime_inversa (tam, array);
    }
}


int main ()
{
    int t, h;
    int *pt, *ph;
    scanf ("%d", &t);
    h = t;
    pt = &t;
    ph = &h;

    int array[*pt];

    // lendo os números
    int j = 0;
    for (int *pj = &j; *pj < *pt; (*pj)++) {
        scanf ("%d", (array + *pj));
    }

    imprime_inversa ( pt , array );
    desloca ( ph , array );
    ordenacao ( ph , array );

    return 0;
}
