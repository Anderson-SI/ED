#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct no {
    int dado;
    struct no *dir;
    struct no *esq;
} No;

No *inicializar(void)
{
    return NULL;
}

void varrer( No *arv ) // e-r-d
{
    if (arv != NULL) {
        varrer ( arv->esq );
        printf ("%d\n", arv->dado);
        varrer ( arv->dir );
    }
}

No* criar (int k)
{
    No *novo = malloc ( sizeof ( No ));
    novo->dado = k;
    novo->esq = novo->dir = NULL;
    return novo;
}

// implementação para árvore binária de busca
// insere os elementos de forma ordenada
No *insere (No *r, No *novo)
{
    if (r == NULL) { return novo; }
    if (r->dado > novo->dado)
        r->esq = insere ( r->esq, novo );
    else
        r->dir = insere ( r->dir, novo );
    return r;
}


void treeLiberar( No *r)
{
    if ( No != NULL)
    {
        treeLiberar( r->esq);
        treeLiberar( r->dir);
        free( r );
    }
}

int conta_no (No *raiz)
{
    if (raiz->dado == (-1)) { return 0; }
    else {
        int conte = conta_no ( raiz->esq );
        int conted = conta_no ( raiz->dir );
        return 1 + conte + conted;
    }
}

void varrer (No *r)
{
    if (r != NULL) {
        varrer ( r->esq );
        printf ("%d ", r->dado);
        varrer ( r->dir );
    }
}


int main ()
{


    No *r = inicializar ();
    r = insere (r, criar (10) );
    r = insere (r, criar (2) );
    r = insere (r, criar (1) );
    r = insere (r, criar (5) );
    r = insere (r, criar (7) );
    r = insere (r, criar (12) );
    r = insere (r, criar (19) );

    varrer ( r );

    // (5(4(11(7()())(2()()))()) (8(13()())(4()(1()()))))








    return 0;
}
