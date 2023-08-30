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

void fImprimir (Celula *fila)
{
    Celula *aux;
    for (aux = fila->prox; aux != NULL; aux = aux->prox)
    {
        printf ("%d ", aux->dado);
    }
    printf ("\n");
}

void fPreencherFila (char *s, Celula *fila)
{
    int num = 0;
    int bol = 0;
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
}


// estrutura da árvore
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

void construirArvore (No *raiz, Celula *fila)
{
    if (raiz->dado == -1) { return; }
    if (fila->prox != NULL) {
            raiz->esq = criarNo ( fila );
            construirArvore( raiz->esq , fila );
    }
    if (fila->prox != NULL) {
        raiz->dir = criarNo ( fila );
        construirArvore( raiz->dir , fila);
    }
}

void construirArvorePrincipal (No *arvore, No *raiz)
{
    if (arvore != NULL && arvore->dado != (-1)) {
        construirArvorePrincipal ( arvore->esq , raiz);
        if (arvore->dado == raiz->dado)
        {
            arvore = raiz;
        }
        construirArvorePrincipal ( arvore->dir , raiz);
    }
}



int main ()
{

    // (5(4(11(7()())(2()()))()) (8(13()())(4()(1()()))))
    char s[200];

    Celula **m = malloc (100 * sizeof ( Celula ));

    gets ( s );


    // lendo as árvores
    int i = 0;
    while (s[0] == '(' && s[1] != ')')
    {
        Celula *fila = fcriar();
        fPreencherFila ( s, fila );
        *(m+i) = fila;
    i++;
    gets ( s );
    }

    No **ma = malloc (i * sizeof ( No ));
    Celula *fila = *(m);
    No *arvoreMatriz = criarNo ( fila );
    construirArvore (arvoreMatriz, fila );

    for (int j = 1; j < i; j++)
    {
        Celula *fila = *(m+j);
        No *raiz = criarNo ( fila );
        construirArvore (raiz, fila );
        *(ma+(j - 1)) = raiz;
    }
    free( m );

    for (int h = 0; h < (i - 1); h++)
    {
        construirArvorePrincipal (arvoreMatriz , *(ma+h));
    }



    varrer ( arvoreMatriz );






    return 0;
}

