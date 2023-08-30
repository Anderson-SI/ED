#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char byte;

int m = 1;
int n = 120;
byte *b; // texto
byte *a; // prinmeiro caracter
byte c; // segundo caracter


int contacaracter (byte *str)
{
    int car = 0;
    while (*(str + car) != '\0') { car++; }
    return car;
}

void boyermoore2 (byte a[], int m, byte b[], int n, byte c)
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
    // int ocorrs = 0;
    k = m-1;
    while (k <= n) {
      int i = m-1, j = k;
      while (i >= 0 && a[i] == b[j]) { --i; --j; }
      if (i < 0) { *(b+k) = c; } // encontrou uma ocorrência
      if (i == m-1) { k += 1; } // anda uma casa
      else { k += (m-1) - jump[i+1]; } // avança casas
    }
    // return ocorrs;
}


void entrada ()
{
    gets(b); // string
    fflush(stdin);
    gets(a); // primeiro caracter
    fflush(stdin);
    scanf("%c", &c); // segundo caracter
}



int main ()
{

    b = malloc ( n * sizeof ( byte ));
    a = malloc ( m * sizeof ( byte ));
    entrada ();
    n = contacaracter (b);

    boyermoore2 (a, m, b, n, c);

    printf("%s\n", b);


    return 0;
}

