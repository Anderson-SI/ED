#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// estrutura fila
typedef struct celula {
    int dado;
    struct celula *prox;
} Celula;

Celula *fcriar ( void )
{
    Celula *novo = malloc ( sizeof ( Celula ) );
    novo->prox = NULL;
    return novo;
}

void fInserir (Celula *fila, int k)
{
    Celula *novo = malloc ( sizeof ( Celula ));
    novo->dado = k;
    novo->prox = NULL;
    if (fila == NULL) { fila->prox = novo; }
    else {
        Celula *p = fila;
        while (p->prox != NULL) { p = p->prox; }
        p->prox = novo;
    }
}

void fRemover ( Celula *fila )
{
    Celula *lixo;
    if (fila->prox != NULL) {
        lixo = fila->prox;
        fila->prox = lixo->prox;
        free(lixo);
    }
}

void imprimirF (Celula *fila)
{
    Celula *aux;
    for (aux = fila->prox; aux != NULL; aux = aux->prox)
    {
        printf ("%d ", aux->dado);
    }
    printf ("\n");
}

//


// Estrutura da Árvore
typedef struct no {
    int dado;
    struct no *dir;
    struct no *esq;
} No;

No *criarArvore (void)
{
    return NULL;
}

void varrer( No *arv ) // e-r-d
{
    if (arv != NULL) {
        varrer ( arv->esq );
        printf ("%d ", arv->dado);
        varrer ( arv->dir );
    }
}

No* criarNo (Celula *fila)
{
    No *novo = malloc ( sizeof ( No ));
    novo->dado = fila->prox->dado;
    novo->esq = novo->dir = NULL;
    fRemover ( fila );
    return novo;
}

void construirArvore (No *r, Celula *fila)
{
    if (r->dado == -1) { return; }
    if (fila->prox != NULL) {
            r->esq = criarNo ( fila );
            construirArvore( r->esq , fila );
    }
    if (fila->prox != NULL) {
        r->dir = criarNo ( fila );
        construirArvore( r->dir , fila);
    }
}

int fordem ( No *arvore )
{
    if (arvore->dado == -1){ return 1;}
    if (arvore->esq != NULL) {
        if (arvore->esq->dado > arvore->dado) { return 0; }
        fordem (arvore->esq);
    }
    if (arvore->dir != NULL) {
        if (arvore->dir->dado < arvore->dado && arvore->dir->dado != -1) { return 0; }
        fordem (arvore->dir);
    }
}


int main ()
{

    // (5(4(11(7()())(2()()))()) (8(13()())(4()(1()()))))
    char s[200];
    gets ( s );

    int num = 0;
    int bol = 0;
    Celula *fila = fcriar ();

    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            num = num * 10 + (s[i] - '0');
            bol = 1;
        }
        else
        {
            if (s[i] == ')' && s[i - 1] == '('){ fInserir ( fila, -1); }
            else if (bol) { fInserir ( fila, num); }
            num = 0;
            bol = 0;
        }
    i = i + 1;
    }

    No *raiz = criarArvore ();
    raiz = criarNo ( fila );
    construirArvore ( raiz, fila );

    int ordem = fordem ( raiz );

    if (ordem) { printf ("VERDADEIRO\n"); }
    else { printf ("FALSO\n"); }














    return 0;
}
