#include <stdio.h>
#include <stdlib.h>

// Fun��o recursiva que recebe um ponteiro de n�mero inteiro
// imprime o valor em n de forma regressiva
void contRegressiva (int *n)
{
    if (*n == 1) printf ("%d\n", *n);
    else {
        for (int j = 0; j < *n - 1; j++) {
            printf ("%d-", *n);
        }
        printf ("%d\n", *n);
        *n = *n - 1;
        contRegressiva (n);
    }
}

int main ()
{
    int n;
    int *p;
    scanf ("%d", &n);
    p = &n;
    // Chamada a Fun��o contRegressiva
    contRegressiva (p);



    return 0;
}
