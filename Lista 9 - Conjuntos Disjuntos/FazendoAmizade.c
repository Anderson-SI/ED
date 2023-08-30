#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Tópico
// conjuntos disjuntos
// Quarta Implementação

void Initialize4 ( int *chefe, int *alt, int n)
{
    for (int v = 1; v <= n; v++) {
        chefe[v] = v;
        alt[v] = 0;
    }

    for (int t = 1; t <= n; t++) {
        printf ("%d.", chefe[t]);
    }
    printf ("\t");
    for (int t = 1; t <= n; t++) {
        printf ("%d.", alt[t]);
    }
    printf ("\n");

}

int Find4 (int *chefe, int v ) {// path-compression
    if ( v != chefe[v] ) {
        chefe[v] = Find4 ( chefe, chefe[v] );
    }
    return chefe[v];
}

void Union4 (int *chefe, int *alt, int r, int s) { // union-by-rank; r ≠ s
    if ( alt[r] > alt[s] ) {
        chefe[s] = r;
    }
    else {
        chefe[r] = s;
        if( alt[r] == alt[s] ) {
            alt[s] = alt[r] + 1;
        }
    }
    /*
    for (int t = 1; t <= 4; t++) {
        printf ("%d|", chefe[t]);
    }
    printf ("\t");
    for (int t = 1; t <= 4; t++) {
        printf ("%d|", alt[t]);
    }
    printf ("\n");
    */
}

// OBS: prestar atenção nas variáveis
int componentes ( int *chefe, int n) // n é o número de vértices
{
    int c = n-1;
    for (int r = 1; r <= n; r++) { // 12 é tomanho do Array que foi lido de entrada, ou seja, a quantidade de árestas
        int v = chefe[r];
        int s = chefe[v];
        if ( r != s) {
            c = c - 1;
        }
    }
    return c;
}

int main ()
{
    int N, M; // N => núm. de alunos, M => núm. de linhas
    int T, A, B; // T => Tipo de acontecimento, A e B alunos;
    char c;
    /*  Saída um inteiros para cada entrada do tipo 2
      responder a seguinte pergunta pergunta qual a quantidade mínima de
      amizades que podem ser feitas para que todas as N crianças sejam
      amigas entre-si.

    */
    scanf ("%d%c%d", &N, &c, &M); // entrada
    int *chefe = malloc ((N+1) * sizeof ( N ));
    int *alt = malloc ((N+1) * sizeof ( N ));

    Initialize4 ( chefe, alt, N );

    for (int i = 0; i < M; i++)
    {
        scanf("%d%c", &T, &c);
        if (T == 1) {
            scanf ("%d%c%d", &A, &c, &B);
            if (Find4 (chefe, A) != Find4 (chefe, B))
                Union4 ( chefe, alt, A, B );
        }
        else if (T == 2) {
            int c = componentes ( chefe, N );
            printf ("%d\n", c);
        }

    }







    return 0;
}
