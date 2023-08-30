#include <stdio.h>
#include <stdlib.h>

float* leDados (int *i)
{
    float *v = malloc ((*i) * sizeof ( float ));
    int n;
    for (int k = 0; k < (*i); k++)
    {
        scanf ("%f", (v + k));
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

void buscaBinaria (int ini, int tam, int *vInt, float *vOri, int *vInd, float ele, int *oc)
{
    int t = tam-1;
    int meio;

    if (ini <= t)
    {
        meio = (ini + t) / 2;
        if (*(vOri + meio) == ele) {
            *(vInd + *oc) = meio;
            *oc = *oc + 1;
        }
        buscaBinaria (ini, meio, vInt, vOri, vInd, ele, oc); // esquerdo
        buscaBinaria (meio + 1, tam, vInt, vOri, vInd, ele, oc); // direito
    }
}


void imprimir (int *t, int *v)
{
    for (int k = 0; k < *t; k++) {
        printf ("%d\n", *(v + k));
    }
}


int main ()
{
    int tam = 101, oc = 0;
    int *ptam = &tam, *poc = &oc;

    printf ("Digite a sequencia de numero:\n");
    float *v = leDados ( &tam );
    float ultimo = *(v + (tam - 1));

    int *vIndice = malloc (100 * sizeof (int)); // vetores que guarda os indices
    int *vInt = malloc (100 * sizeof (int)); // vetor ordenado para passar como parâmentro da busca binária
    for (int k = 0; k <= 100; k++)
    {
        *(vInt + k) = k;
    }

    buscaBinaria (0, 100, vInt, v, vIndice, ultimo, poc);

    *ptam = *ptam - 1;
    insertion ( ptam, vIndice); // ordenar os indeces dos elementos da forma em que foram lidos

    if (*poc != 0){
        printf ("Indice no qual o numero desejado aparece:\n");
        imprimir ( poc, vIndice );
    }


    return 0;
}

