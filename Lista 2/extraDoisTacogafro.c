#include <stdio.h>
#include <stdlib.h>

void funcTacogafro (int *n, int *t, int *v)
{
    int acumulador = 0;
    int *pacum = &acumulador;

    for (int j = 0; j < *n; j++)
    {
        scanf ("%d%d", t, v);
        *pacum = *pacum + ((*t) * (*v));
    }

     printf ("%d\n", *pacum);
     return;
}

int main ()
{

    int n;
    int t, v;
    scanf ("%d", &n);
    funcTacogafro (&n, &t, &v);


    return 0;
}

