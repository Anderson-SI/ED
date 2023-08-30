#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void Initialize3 ( int *chefe, int *alt, int n)
{
    for (int v = 1; v <= n; v++) {
        *(chefe + v) = v;
        *(alt + v) = 0;
    }
}

int Find4(int x, int *chefe) {

    if ( *(chefe + x) == x)
        return x;
    else
        *(chefe + x) = Find4( *(chefe + x), chefe );
    return *(chefe + x);
}

void Union3(int a, int b, int *chefe, int *alt, int *ptrN ) {
    int x = Find4( a, chefe ), y = Find4( b, chefe );
    if ( x == y) return;
    if ( *(alt + x) < *(alt + y)) {
        *(chefe +x) = y;
        *ptrN = *ptrN - 1;
    }
    else {
        *(chefe + y) = x;
        *ptrN = *ptrN - 1;
        if (*(alt + x) == *(alt + y)) alt[x]++;
    }
}

void componentes ( int *chefe, int n)
{
    int c = n-1;
    int r = 1;
    while (r <= n) {
        int s = chefe[r];
        if ( r != s) {
            c = c - 1;
        }
    r++;
    }
    printf ("%d\n", c);
}


int main()
{

    int N, K; // N => núm. de alunos, M => núm. de linhas
    int BA, BB; //  BA e BB  são bancos;
    char OP; // operação
    char c; // scape do espaço

    scanf ("%d%c%d", &N, &c, &M); // entrada

    int *chefe = malloc ((N+1) * sizeof ( N ));
    int *alt = malloc ((N+1) * sizeof ( N ));

    Initialize3 ( chefe, alt, N ); // inicializa os vetores

    for (int i = 0; i < K; i++)
    {
        scanf("%c%c%d%c%d", &OP, &c, &A, &c, &B);
        if (OP == 'C') {
            Union3 ( A, B, chefe, alt, &N );
        }
        else if (OP =='F') {
            // componentes ( chefe, N );
            printf ("%d\n", N - 1);
        }
    }

    return 0;
}
