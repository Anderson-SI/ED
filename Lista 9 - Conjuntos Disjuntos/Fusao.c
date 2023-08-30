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

void mesmoChefe (int *vChefe, int ch, int v, int N)
{
    for (int j = 1; j <= N; j++) {
        if (*(vChefe + j) == ch) {
            *(vChefe + j) = v;
        }
    }
}

int Find4(int x, int *chefe) {
    if ( *(chefe + x) != x)
        *(chefe + x) = Find4( *(chefe + x), chefe );
    return *(chefe + x);
}

void Union3(int a, int b, int *chefe, int *alt, int N) {
    int x = Find4( a, chefe ), y = Find4( b, chefe );
    if ( x == y) return;
    if ( *(alt + x) < *(alt + y)) {
        //int ch = *(chefe +x);
        *(chefe +x) = y;
        //mesmoChefe ( chefe, ch, y, N);
    }
    else {
        //int ch = *(chefe +y);
        *(chefe + y) = x;
        //mesmoChefe ( chefe, ch, x, N);
        if (*(alt + x) == *(alt + y)) alt[x]++;
    }
}

int main()
{

    int N, K; // N => n�m. de alunos, M => n�m. de linhas
    int BA, BB; //  BA e BB  s�o bancos;
    char tConsulta; // opera��o
    char cc, ccc; // scape do espa�o

    scanf ("%d%c%d", &N, &cc, &K); // entrada
    getchar();

    int *chefe = malloc ((N+1) * sizeof ( N ));
    int *alt = malloc ((N+1) * sizeof ( N ));

    Initialize3 ( chefe, alt, N ); // inicializa os vetores

    for (int i = 0; i < K; i++)
    {
        scanf ("%c%c%d%c%d", &tConsulta, &cc, &BA, &ccc, &BB);
        getchar ();
        if (tConsulta == 'F') {
            Union3 (BA, BB, chefe, alt, N);
        }
        else if (tConsulta == 'C') {
            if (Find4 (BA, chefe) == Find4 (BB, chefe)) { printf ("S\n"); }
            else { printf ("N\n"); }
        }
    }

    return 0;
}
