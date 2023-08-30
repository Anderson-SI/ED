#include <stdio.h>
#include <stdlib.h>

int* leDados (int *i)
{
    int *v = malloc ((*i) * sizeof ( int ));
    int n;
    for (int k = 0; k < (*i); k++)
    {
        scanf ("%d", (v + k));
    }
    return v;
}

void insertion (int *tam, int *array)
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

int buscaBinaria (int ini, int tam, int *v, int ele)
{
    int t = tam-1;
    int meio;

    while (ini <= t)
    {
        meio = (ini + t) / 2;

        if (ele < *(v + meio)) { t = meio - 1; }
        else if (ele > *(v + meio)) { ini = meio + 1; }
        else { return meio; }
    }
    return -1;
}


void fOcorrencia (int *oc, int ini, int tam, int *v, int elem, int *vM)
{
    int i = buscaBinaria (ini, tam, v, elem);
    if (i != (-1)) {
        *(vM + *oc) = i;
        *oc = *oc + 1;
        if (*(v + (i - 1)) == elem && *(v + (i + 1)) == elem) {
            fOcorrencia ( oc, (i + 1), tam, v, elem, vM); // direita
            fOcorrencia ( oc, ini, i, v, elem, vM); // esquerda
        } else if (*(v + (i - 1)) == elem && *(v + (i + 1)) != elem) {
            fOcorrencia ( oc, ini, i, v, elem, vM); // esquerda
        } else if (*(v + (i - 1)) != elem && *(v + (i + 1)) == elem) {
            fOcorrencia ( oc, (i + 1), tam, v, elem, vM); // direita
        }
    }
}

void imprimr (int *t, int *v)
{
    for (int k = 0; k < *t; k++)
        printf ("%d", *(v + k));
    printf ("\n");
}


int main ()
{
    int tam;
    int maior, maiorV = 0, menor, menorV = 0;
    int *ocMaior = &maiorV, *ocMenor = &menorV;

    scanf ( "%d", &tam );
    int *v = leDados ( &tam );

    int *pMaior = malloc (tam * sizeof (int)); // vetores que guardam os indices em que os elementos aparecem
    int *pMenor = malloc (tam * sizeof (int)); // vetores que guardam os indices em que os elementos aparecem

    insertion ( &tam, v );
    menor = *(v);
    maior = *(v + (tam - 1));


    fOcorrencia (ocMaior, 0, tam , v, maior, pMaior);
    fOcorrencia (ocMenor, 0, tam , v, menor, pMenor);

    //imprimr ( ocMaior, pMaior);

    printf ("Maior: %d apareceu %d vezes\n", maior, *ocMaior);
    printf ("Menor: %d apareceu %d vezes\n", menor, *ocMenor);






    return 0;
}
