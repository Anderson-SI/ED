#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct no {
    int dado;
    struct no *dir, *esq;
} noh; // nó

typedef noh *arvore; // arvore

arvore *idnoh;

int altura(arvore r)
{
    if (r == NULL) {
        return -1; // altura da árvore vazia
    }
    else {
        int he = altura (r->esq);
        int hd = altura (r->dir);
        if (he < hd) return hd + 1;
        else return he + 1;
    }

}

void red(arvore r)
{
    if (r != NULL) {
        printf ("%d", r->dado);
        red ( r->esq );
        red ( r->dir );
    }
}


noh* novono ( int k )
{
    noh *novo = malloc (sizeof ( noh ));
    novo->dado = k;
    novo->esq = novo->dir = NULL;
    return novo;
}


// função de liberar uma árvore
void freeTree(arvore r)
{
    if (r != NULL)
    {
        freeTree ( r->esq );
        freeTree ( r->dir );
        free( r );
    }
}

// função de busca
arvore treeSearch (arvore r, int k)
{
    if (r != NULL)
    {
        if (r->dado == k)
            return r;
        else
        {
            if (k > r->dado)
                return treeSearch (r->esq, k);
            else
                return treeSearch (r->dir, k);
        }
    }
}

arvore treeMin (arvore r)
{
    if (r != NULL)
    {
        arvore aux;
        while (aux->esq != NULL) { aux = aux->esq; }
        return aux;
    }
    return NULL;

}



// deletando elemento da árvore
arovre treeDelete (arvore r, int k)
{
    if (r != NULL)
    {
        if (k > r->dado) { r->dir = treeDelete (r->dir, k); }
        else if (k < r->dado) { r->esq = treeDelete ( r-esq, k); }
        else
        {
            if (r->esq == NULL && r->dir == NULL)
            {
                free( r );
                return NULL;
            }
            else if (r->esq == NULL && r->dir != NULL)
            {
                arvore aux = r->dir;
                free(r);
                return aux;
            }
            else if (r->esq != NULL && r->dir == NULL)
            {
                arvore aux = r->esq;
                free( r );
                return aux;
            }
            else
            {
                arvore aux = treeMin ( r->dir );
                int k = aux->dado;
                r = treeDelete (r, k);
                r->dado = k;
            }
        }
        return r;
    }
    else
        return NULL;
}




int main ()
{

    int n, *pn = &n;
    int k, *pk = &k;
    int r, *pr = &r;

    int S, *pS = &S;
    int L, *pL = &L;
    int R, *pR = &R;

    scanf ("%d %d %d", pn, pk, pr);

    idnoh = malloc (*pn * sizeof ( arvore ));

    for (int i = 0; i < *pk; i++)
    {
        scanf ("%d %d %d", pS, pL, pR);

        if (idnoh[ *pS ] == NULL) idnoh[ *pS ] = novono( *pS );

        if (*pL != -1 ) {
            if (idnoh[ *pL ] == NULL ) idnoh[ *pL ] = novono( *pL );
            idnoh[ *pS ]->esq = idnoh[ *pL ];
        }
        if (*pR != -1) {
            if (idnoh[ *pR ] == NULL) idnoh[ *pR ] = novono( *pR );
            idnoh[ *pS ]->dir = idnoh[ *pR ];
        }
    }

    // red ( idnoh[ *pr ])
    if ( *pn == 1 && *pk == 0 && *pr == 0) { printf ("%d", 1); }
    else printf ("%d", altura ( idnoh[ *pr ] ) + 1);





    return 0;
}
