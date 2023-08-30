#include <stdio.h>
#include <stdlib.h>


int hash (char *ch, int *ph)
{
    int soma = 0;
    int j = 0;
    while (*(ch + j) != '\0')
    {
        soma = soma + (*(ch + j) - 65) + *ph + j ;
    j++;
    }
    return soma;
}


int main ()
{

    int n, l;
    scanf ("%d", &n);

    int j = 0;
    for (int *pj = &j; *pj < n; (*pj)++)
    {
        int valor = 0;
        char *ch = malloc (50 * sizeof ( char ));

        scanf ("%d", &l);

        int h = 0;
        for (int *ph = &h; *ph < l; (*ph)++)
        {
            scanf ("%s", ch);
            valor = valor + hash ( ch, ph );
        }
        printf ("%d\n", valor);
    }






    return 0;
}

