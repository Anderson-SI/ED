#include <stdio.h>
#include <stdlib.h>

// Constante PI
#define PI 3.1416

// Função volumeEsfera recebe um ponteiro para uma variável que representa o valor
// do raio de uma esfera
// Imprime o volume da esfera
double volumeEsfera (double *r) {
    return 4 * PI * ((*r) * (*r) * (*r)) / 3;
}

int main ()
{

    double r1, r2, r3;
    double *pr1, *pr2, *pr3; // Ponteiros

    scanf ("%lf", &r1);
    scanf ("%lf", &r2);
    scanf ("%lf", &r3);

    pr1 = &r1;
    pr2 = &r2;
    pr3 = &r3;

    printf ("%.2f\n", volumeEsfera (pr1));
    printf ("%.2f\n", volumeEsfera (pr2));
    printf ("%.2f\n", volumeEsfera (pr3));


    return 0;
}
