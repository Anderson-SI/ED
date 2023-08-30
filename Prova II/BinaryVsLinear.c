#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Tópicos: Árvore

int x, *px = &x; // nº comparações busca linera
int y, *py = &y; // nº comparações busca binária
int n, k, req;
int *vt;


// strutura arvore
typedef struct no {
    int dado;
    struct no *esq, *dir;
} No;

No *criarArvore (void)
{
    return NULL;
}

// apenas para conferir se a árvores está construida de forma correta
void varrer( No *arv ) // e-r-d
{
    if (arv != NULL) {
        varrer ( arv->esq );
        printf ("%d ", arv->dado);
        varrer ( arv->dir );
    }
}

No* criarNo ( int k )
{
    No *novo = malloc ( sizeof ( No ));
    novo->dado = k;
    novo->esq = novo->dir = NULL;
    return novo;
}

No* construirArvore (No *r, int k)
{
    if (r == NULL) { return criarNo ( k ); }
    else
    {
        if ( r->dado < k ) { r->dir = construirArvore (r->dir, k); }
        else if (r->dado > k) { r->esq = construirArvore (r->esq, k); }
    }
    return r;
}

void buscaLinear ( int *v, int n, int req, int *px)
{
    while (*px < n && *(v + (*px)) != req) { *px = *px + 1; }
    if (*(v + (*px)) == req) { *px = *px + 1; }
}

void buscaBinaria (No *r, int req, int *py)
{
    if (r == NULL) { return; }
    else
    {
        if (r->dado == req) { *py = *py + 1; return; }
        else if (r->dado < req ) { *py = *py + 1; buscaBinaria (r->dir, req, py); }
        else if (r->dado > req) { *py = *py + 1; buscaBinaria (r->esq, req, py); }
    }
}



int main ()
{

    No *r = criarArvore ();

    scanf ("%d", &n);
    vt = malloc ( n * sizeof ( int ));

    // inserindo dados no vetor
    // construindo a árvore
    for (int i = 0; i < n; i++) {
        scanf ("%d", &k);
        *(vt + i) = k;
        r = construirArvore (r, k);
    }


    while (scanf ("%d", &req) != EOF)
    {
        *px = 0; *py = 0;
        buscaLinear ( vt, n, req, px);
        buscaBinaria (r, req, py);
        printf ("%d %d\n", *px, *py);
    }




    return 0;
}
