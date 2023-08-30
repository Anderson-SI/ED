#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char byte;

int m = 255;
int n = 255;
byte *b; // texto
byte *a; // palavra

int contacaracter (byte *str)
{
    int car = 0;
    while (*(str + car) != '\0') { car++; }
    return car;
}

int boyermoore2 (byte a[], int m, byte b[], int n)
{
    int *jump = malloc ((m) * sizeof (int)); // usaremos jump[1..m]

    // pré-processamento da palavra a
    int h = m-1, k = m-2;
    int i = m-1, j = k;
    while (h >= 0) {
    while (i >= h && j >= 0)
        if (a[i] == a[j]) --i, --j;
        else i = m-1, j = --k;
    jump[h--] = k;
    }
    while (h >= 1) { jump[h--] = k; }

    // busca da palavra a no texto b
    int ocorrs = 0;
    k = m-1;
    while (k <= n) {
      int i = m-1, j = k;
      while (i >= 0 && a[i] == b[j]) { --i; --j; }
      if (i < 0) ++ocorrs; // encontrou uma ocorrência
      if (i == m-1) k += 1; // anda uma casa
      else k += (m-1) - jump[i+1]; // avança casas
    }
    return ocorrs;
}


void entrada ()
{
    gets(b);
    fflush(stdin);
    gets(a);
}



int main ()
{

    b = malloc ( n * sizeof ( byte ));
    a = malloc ( n * sizeof ( byte ));
    entrada ();
    m = contacaracter (a);
    n = contacaracter (b);

    int oc = boyermoore2 (a, m, b, n);

    printf("%d\n", oc);


    return 0;
}
