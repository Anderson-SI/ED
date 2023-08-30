#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void organiza (int *t, char *array)
{
    int n;
    int *pn = &n;
    char c, cc;
    char *pcc = &cc;

    int i = 0;
    for (int *pi = &i; *pi < *t; (*pi)++) {
        scanf ("%d%c%c", &n,&c,&cc);
        *(array + (*pn-1)) = *pcc;
    }
    *(array + *t) = '\0';
}


int main ()
{
    int t;
    scanf ("%d", &t);

    char array[t+1];

    organiza ( &t, array );

    printf ("%s\n", array);



    return 0;
}
