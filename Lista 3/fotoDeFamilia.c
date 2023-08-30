#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void ordena_ (float *array)
{
    for (int k = 1; k < 4; k++) {
        if (*(array+k) < *(array)) {
            float menor = *(array+k);
            *(array+k) = *(array);
            *(array) = menor;
        }
    }
    for (int k = 1; k < 4; k++) {
        if (*(array+k) > *(array+2)) {
            float maior = *(array+k);
            *(array+k) = *(array+2);
            *(array+2) = maior;
        }
    }
    if (*(array + 1) < *(array+3)) {
        float aux = *(array + 1);
        *(array + 1) = *(array + 3);
        *(array + 3) = aux;
    }
}


int main ()
{


    float array[4];

    scanf ("%f", array);
    scanf ("%f", (array + 1));
    scanf ("%f", (array + 2));
    scanf ("%f", (array + 3));


    ordena_ ( array );

    int k = 0;
    for (int *pk = &k; *pk < 4; (*pk)++) {
        printf ("%.2f\n", *(array+*pk));
    }



    return 0;
}
