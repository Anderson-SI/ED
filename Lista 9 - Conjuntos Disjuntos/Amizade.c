#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Tópico
// heap, set, conjuntos disjuntos

void Initialize3 ( int *chefe, int *alt, int n)
{
    for (int v = 1; v <= n; v++) {
        *(chefe + v) = v;
        *(alt + v) = 0;
    }
    /*
    for (int t = 1; t <= n; t++) {
        printf ("%d.", chefe[t]);
    }
    printf ("\t");
    for (int t = 1; t <= n; t++) {
        printf ("%d.", alt[t]);
    }
    printf ("\n");
    */
}

void mesmoChefe (int *vChefe, int ch, int v, int N)
{
    for (int j = 1; j <= N; j++) {
        if (*(vChefe + j) == ch) {
            *(vChefe + j) = v;
        }
    }
}

int Find4(int x, int *chefe) {

    if ( *(chefe + x) == x)
        return x;
    else
        *(chefe + x) = Find4( *(chefe + x), chefe );
    return *(chefe + x);
}

void Union3(int a, int b, int *chefe, int *alt, int n) {
    int x = Find4( a, chefe ), y = Find4( b, chefe );
    if ( x == y) return;
    if ( *(alt + x) < *(alt + y)) {
        int ch = *(chefe +x);
        *(chefe + x) = y;
        mesmoChefe ( chefe, ch, y, n );
    }
    else {
        int ch = *(chefe +y);
        *(chefe + y) = x;
        mesmoChefe ( chefe, ch, x, n );
        if (*(alt + x) == *(alt + y)) alt[x]++;
    }

    /* aqui teste
    for (int t = 1; t <= n; t++) {
        printf ("%d.", chefe[t]);
    }
    printf ("\t");
    for (int t = 1; t <= n; t++) {
        printf ("%d.", alt[t]);
    }
    printf ("\n");
    */
}



int main ()
{
    int cTeste; // cTeste => Número de casos de testes
    char a; // escape do espaço em branco
    // saída um inteiro que responde quantas pessoas há no maior grupo de amigos

    scanf ("%d", &cTeste); // entrada


    while (cTeste) {
        int N, M; // N => pessoas da cidade e M => número de pares de pessoas
        int A, B; // A e B são amigos

        scanf ("%d%c%d", &N, &a, &M);

        int *chefe = malloc ((N+1) * sizeof ( N ));
        int *alt = malloc ((N+1) * sizeof ( N ));
        Initialize3 ( chefe, alt, N );

        for (int i = 0; i < M; i++)
        {
            scanf ("%d%c%d", &A, &a, &B);
            Union3 (A, B, chefe, alt, N);
        }
        int h = 0;
        for (int f = 1; f <= N; f++) {
            if (alt[f] != 0) {
                int t = 0;
                for (int z = 1; z <= N; z++) {
                    if (*(chefe+z) == f) {
                        t++;
                    }
                }
                if ( t > h) {
                    h = t;
                }
            }
        }
        printf ("%d\n", h);
    cTeste--;
    }


    return 0;
}

