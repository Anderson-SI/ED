#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int dir[8];
int chefe[8];
int alt[8];


int Find( int v ) // recebe um vértice v e devolve o diretor da componente a que v pertence
{
    return dir[v];
}

void Union (int r, int s)
{
    for (int v = 0; v < 8; v++) {
        if ( dir[v] == r) {
            dir[v] = s;
        }
    }
    // mostrando fazendo a união
    for (int v = 0; v < 8; v++) {
        printf ("%d|", dir[v]);
    }
    printf ("\n");

}

void initialize()
{
    for ( int v = 0; v < 8; v++) {
        dir[v] = v;
    }
    // mostrando o ventor inicializado
    for (int v = 0; v < 8; v++) {
        printf ("%d.", dir[v]);
    }
    printf ("\n");

}


// Quarta Implementação
void Initialize4 ( )
{
    for (int v = 0; v < 8; v++) {
        chefe[v] = v;
        alt[v] = 0;
    }
}

int Find4 ( int v ) {// path-compression
    if ( v != chefe[v] ) {
        chefe[v] = Find4 ( chefe[v] );
    }
    return chefe[v];
}

void Union4 (int r, int s) { // union-by-rank; r ≠ s
    if ( alt[r] > alt[s] ) {
        chefe[s] = r;
    }
    else {
        chefe[r] = s;
        if( alt[r] = alt[s] ) {
            alt[s] = alt[r] + 1;
        }
    }
}

// OBS: prestar atenção nas variáveis
int componentes ( char *G, int n ) // n é o número de vértices
{
    //int i = 0;
    int cc = 0;
    int c = n;
    Initialize4();
    for (int i = 0; i < 12; i++) { // 12 é tomanho do Array

        int u = G[cc++] - '0'; //printf (" %d:", u);
        int v = G[cc++] - '0'; //printf (" %d:", v);
        cc++;
        int r = Find4 ( u );
        int s = Find4 ( v );
        if ( r != s) {
            Union4 (r , s);
            c = c - 1;
        }
    }
    return c;
}


/*  QUARTA IMPLEMENTAÇÃO

    Find-4 (v) // path-compression
    1  se v ≠ chefe[v]
    2       chefe[v] := Find-4 ( chefe[v] )
    3  devolva chefe[v]

    obs: Os códigos de Union-4 e Initialize-4 são identicas as da 3ª implementação

    Union-3 (r, s)  // union-by-rank; r ≠ s
    1  se alt[r] > alt[s]
    2       chefe[s] := r
    3  senão chefe[r] := s
    4       se alt[r] = alt[s]
    5           alt[s] := alt[r] + 1


    Initialize-3 ( )
    1  para cada vértice v
    2       chefe[v] := v
    3  alt[v] := 0
*/






int main ()
{

    char * G = "53 71 76 20 07 01 34 54 74 06 46 05";
    int c = componentes ( G, 8); // o 8 representa o número de componentes conexas que existem;
    printf ("[%d]\n", c);





    return 0;
}


