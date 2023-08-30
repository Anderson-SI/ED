#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char byte;

int n = 50;
byte *pb; // texto
byte a; // palavra
byte *pa = &a;

int contaocorrencias ()
{
    int ocorrs = 0;
    int i = 0;
    while (*(pb + i) != '\0') {
        if (*(pb + i) == a)
            ocorrs++;
    i++;
    }
    return ocorrs;
}


void entrada ()
{
    gets(pb);
    fflush(stdin);
    scanf("%c", pa);
}



int main ()
{

    pb = malloc ( n * sizeof ( byte ));
    entrada ();
    int ocor = contaocorrencias ( );
    printf ("%d\n", ocor);



    return 0;
}






