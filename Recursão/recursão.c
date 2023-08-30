#include <stdio.h>
#include <stdlib.h>


// função recursiva recebe um n
// retorna o fatorial de n
int fat (int *n);

float expo (int x, int n);

int imprime (int n);

int soma (int *v, int n);

int buscaSeq (int ele, int tam, int v[]);


// Recursão de segunda ordemm
int fibonacci (int n);


int main (int argv, char *argc[])
{

    int n;
    int v[4] = {1,2,3,4};
    int vv[5] = {3,4,1,7,8};
    scanf ("%d", &n);
    printf ("fatorial de %d = %d\n", n, fat ( &n ));
    printf ("%2.f\n", expo (3, 3));
    imprime (3);
    printf ("%d\n", soma (v, 4));
    printf ("%d\n", fibonacci (6));
    printf ("%d\n", buscaSeq (7, 5, vv));


    return 0;
}

int fat (int *n)
{
    if (*n == 1 || *n == 0)
        return 1;
    else {
        *n = *n - 1;
        return (*n + 1) * fat ( n );
    }
}


float expo (int x, int n)
{
    if (n == 0)
        return 1;
    else
        return x * expo (x, n-1);
}

int imprime (int n)
{
    if (n < 0) return;
    imprime (n-1);
    printf ("%2d\n", n);
}


int soma (int v[], int n)
{
    if (n == 1)
        return v[0];
    else
        return v[n-1] + soma (v, n - 1);
}

int fibonacci (int n) {
    if (n == 0 || n == 1)
        return n;
    else
        return fibonacci (n-1) + fibonacci (n - 2);

}

int buscaSeq (int ele, int tam, int v[])
{
    int i = 0;
    while (v[i] != ele && i < tam) {
        i++;
    }
    if (v[i] == ele)
        return i;
    else
        return (-1);
}





