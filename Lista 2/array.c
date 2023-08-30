#include <stdio.h>
#include <stdlib.h>


void funcParImpar (int *ptrArrPar, int *ptrArrImpar, int *pPar, int *pImp, int *n)
{
    int k = 0, i = 0, h = 0;
    for (int *pk = &k; *pk < 15; (*pk)++)
    {
        int j = 0, z = 0;
        scanf ("%d", n);
        if (*n % 2 == 0) { *(ptrArrPar+*pPar) = *n; (*pPar)++; }
        else  { *(ptrArrImpar+*pImp) = *n; (*pImp)++; }

        if (*pPar == 5) {
            for (int *pj = &j; *pj < *pPar; (*pj)++) {
                printf ("par[%d] = %d\n", *pj, *(ptrArrPar+*pj));
            }
            *pPar = 0;
        }
        else if (*pImp == 5) {
            for (int *pz = &z; *pz < *pImp; (*pz)++) {
                printf ("impar[%d] = %d\n", *pz, *(ptrArrImpar+*pz));
            }
            *pImp = 0;
        }
    }

    for (int *pi = &i; *pi < *pImp; (*pi)++) {
        printf ("impar[%d] = %d\n", *pi, *(ptrArrImpar+*pi));
    }

    for (int *ph = &h; *ph < *pPar; (*ph)++) {
        printf ("par[%d] = %d\n", *ph, *(ptrArrPar+*ph));
    }
}


int main ()
{
    int n;
    int arrayPar[5], arrayImpar[5];
    int ppar = 0, pim = 0;

    funcParImpar (arrayPar, arrayImpar, &ppar, &pim, &n);

    return 0;
}

