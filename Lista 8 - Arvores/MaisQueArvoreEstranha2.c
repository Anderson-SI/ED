#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Estrutura árvore
typedef struct no {
    long int dado;
    struct no *esq;
    struct no *dir;
} No;

No* criarNo (int s)
{
    No *novo = malloc ( sizeof ( No ));
    novo->dado = s;
    novo->esq = novo->dir = NULL;
    return novo;
}

void construirArvore (No *raiz, int **mat, int nLinhas, int *noEsq, int *noDir)
{
    if (raiz != NULL && raiz->dado != (-1)) {
        for (int i = 0; i < nLinhas; i++) {
            if (raiz->dado == mat[i][0])
            {
                if ( mat[i][1] != -1 ) { *noEsq = *noEsq + 1; }
                if ( mat[i][2] != -1 ) { *noDir = *noDir + 1; }
                raiz->esq = criarNo ( mat[i][1] );
                raiz->dir = criarNo ( mat[i][2] );
            }
        }
        construirArvore ( raiz->esq , mat, nLinhas, noEsq, noDir);
        construirArvore ( raiz->dir , mat, nLinhas, noEsq, noDir);
    }
}


int altura (No *raiz)
{
    if (raiz == NULL) { return (-1); }
    else {
        int he = altura ( raiz->esq );
        int hd = altura ( raiz->dir );
        if (he < hd) { return hd + 1; }
        else {
            return he + 1;
        }
    }
}

int main ()
{

    long int nNos, nLinhas, vRaiz; // n = qtd de n?s na ?rvore, k = qtd bolas que tem filhos , vRaiz = bola ra?z;
    long int vNo, es, di;
    char l, ll;

    scanf ("%d%c%d%c%d", &nNos, &l, &nLinhas, &ll, &vRaiz); // lendo a primeira linha
    No *arvore = criarNo ( vRaiz ); // criu o primeiro n?

    int **m = (int**) malloc (nLinhas * sizeof ( int* ));
    int i = 0;
    while (i < nLinhas) {
        *(m+i) = malloc ( 3 * sizeof (long int));
    i++;
    }

    int j = 0;
    while ( j < nLinhas){
        scanf ("%d%c%d%c%d", &vNo, &l, &es, &ll, &di);
        m[j][0] = vNo; m[j][1] = es; m[j][2] = di;
    j++;
    }


    int noEsq = 0, noDir = 0;
    construirArvore ( arvore, m, nLinhas, &noEsq, &noDir);
    if ( noEsq > noDir) { printf ("%d\n", noEsq); }
    else { printf ("%d\n", noDir); }


    //printf ("%d\n", 1 + altura ( arvore ));

    return 0;
}
9 5 0
0 1 2
1 3 4
2 5 -1
3 6 7
4 8 -1

