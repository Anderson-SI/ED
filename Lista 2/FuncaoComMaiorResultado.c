#include <stdio.h>
#include <stdlib.h>

// fun��o que Rafael escolheu
int fRafael (int *x, int *y)
{
  return (9 * ((*x) * (*x)) + ((*y) * (*y)));
}

// Fun��o que Beto escolheu
int fBeto (int *x, int *y)
{
  return (2 * ((*x) * (*x)) + (25 * (*y) * (*y)));
}

// Fun��o que Carlos escolheu
int fCarlos (int *x, int *y)
{
  return  ((-100 * (*x)) + ((*y) * (*y) * (*y)));
}

// fun��o que recento um ponteiro n que representa a quantidade de casos que a fun��o deve testar
// imprime a o nome que a fun��o associda tem maior valor recebidos do usu�rio
void maiorResultado (int *n) {
    int x, y;
    while (*n > 0)
    {
        scanf ("%d%d", &x, &y);

        if (fBeto (&x, &y) > fCarlos (&x, &y) && fBeto (&x, &y) > fRafael (&x, &y))
        {
            printf ("Beto ganhou\n");
        }
        else if (fCarlos (&x, &y) > fBeto (&x, &y) && fCarlos (&x, &y) > fRafael (&x, &y))
        {
            printf ("Carlos ganhou\n");
        }
        else if (fRafael (&x, &y)  > fBeto (&x, &y) && fRafael (&x, &y) > fCarlos (&x, &y))
        {
            printf ("Rafael ganhou\n");
        }
        *n = *n - 1;
    }
    printf ("\n");
}

int main ()
{

    int n;
    scanf ("%d", &n);

    maiorResultado (&n);


    return 0;
}
