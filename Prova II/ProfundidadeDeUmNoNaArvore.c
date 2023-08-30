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

// Estrutura da Árvore
typedef struct no {
    int dado;
    struct no *pai;
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

No* criarNo (Celula *fila, No *nopai)
{
    No *novo = malloc ( sizeof ( No ));
    novo->dado = fila->prox->dado;
    novo->pai = nopai;
    novo->esq = novo->dir = NULL;
    fRemover ( fila );
    return novo;
}

void construirArvore (No *r, Celula *fila)
{
    if (r->dado == -1) { return; }
    if (fila->prox != NULL) {
            r->esq = criarNo ( fila, r );
            construirArvore( r->esq , fila );
    }
    if (fila->prox != NULL) {
        r->dir = criarNo ( fila, r );
        construirArvore( r->dir , fila);
    }
}


// função que busca nó
No* procurar_no(No *r, int x) {
    No *esq;
    if (r == NULL || r->dado == -1) { return NULL; }
    else {
        if (r->dado == x)
            return r;
        esq = procurar_no(r->esq, x);
        if (esq != NULL)
            return esq;
        return procurar_no(r->dir, x);
    }
}

int profundidadeDoNo(No *no, No *raiz)
{
    if (raiz == no) { return 0; }
    else { return 1 + profundidadeDoNo (no->pai, raiz); }
}


int main ()
{

    // (5(4(11(7()())(2()()))()) (8(13()())(4()(1()()))))
    char s[256];
    gets ( s );

    int k;
    int profundidade;
    int p , *pt = &p;
    int dado;
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

    scanf ("%d", &dado);

    No *r = criarArvore ();
    r = criarNo ( fila, NULL);
    construirArvore ( r, fila );


    No *noEncontrado = procurar_no (r, dado);

    if (noEncontrado != NULL) {
        k = profundidadeDoNo (noEncontrado, r );
        printf ("ESTA NA ARVORE\n"); printf ("%d\n", k);
    }
    else {
        printf ("NAO ESTA NA ARVORE\n"); printf ("%d\n", -1);
    }




    return 0;
}


