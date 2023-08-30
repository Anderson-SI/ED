#include <stdio.h>
#include <stdlib.h>



int main ()
{
    int n;
    int pares[5], impares[5], *ptrArrayPares, *ptrArrayImpares;
    int k = - 1, m = - 1, *pk, *pm;

    ptrArrayPares = pares;
    ptrArrayImpares = impares;

    pk = &k;
    pm = &m;




    for (int j = 0; j < 15; j++) {
        scanf ("%d", &n);
        if (n % 2 == 0) {
            pares[*pk + 1] = n;
            *pk = *pk + 1;
        } else {
            impares[*pm + 1] = n;
            *pm = *pm + 1;
        }
        if (*pk == 4) {
            for (int i = 0; i < 5; i++) {
                printf ("par[%d] = %d\n", i, pares[i]);
                *pk = -1;
            }
        } else if (*pm == 4) {
            for (int i = 0; i < 5; i++) {
                printf ("impar[%d] = %d\n", i, impares[i]);
                *pm = -1;
            }
        }
    }

        if (*pk > (-1) || *pm > (-1)) {
            for (int i = 0; i <= *pm; i++) {
                printf ("impar[%d] = %d\n", i, impares[i]);
            }
            for (int i = 0; i <= *pk; i++) {
                printf ("par[%d] = %d\n", i, pares[i]);
                *pm = 0;
            }
        }


    return 0;
}
