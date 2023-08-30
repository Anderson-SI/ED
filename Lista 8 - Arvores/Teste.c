#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Estrutura da lista
typedef struct celula {
    int v[3];
    struct celula *prox;
} Celula;

Celula* criarLista ( void )
{
    Celula *n = malloc ( sizeof ( Celula ));
    n->prox = NULL;
    return n;
}

void inserirNaLista (Celula *lista, int vNo, int vEsq, int vDir )
{
    Celula *n = malloc ( sizeof ( Celula ));
    n->v[0] = vNo;
    n->v[1] = vEsq;
    n->v[2] = vDir;
    Celula *p = lista;
    n->prox = p->prox;
    p->prox = n;
}

void removerNo(Celula *lista , Celula *p)
{
    Celula *aux = lista->prox;
    Celula *auxAn = lista;
    while (aux != p) { aux = aux->prox; auxAn = auxAn->prox; }
    auxAn->prox = aux->prox;
    free(aux);
}

// Estrutura árvore
typedef struct no {
    int dado;
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

void construirArvore (No *raiz, Celula *lista)
{
    if (raiz != NULL && raiz->dado != (-1) && lista->prox != NULL) {
        Celula *p = lista;
        while (p->prox != NULL && p->v[0] != raiz->dado) { p = p->prox; }
        if (raiz->dado == p->v[0])
        {
            raiz->esq = criarNo ( p->v[1] );
            raiz->dir = criarNo ( p->v[2] );
            removerNo( lista, p);
        }
        construirArvore ( raiz->esq , lista);
        construirArvore ( raiz->dir , lista);
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

    int nNos, nLinhas, vRaiz; // n = qtd de nós na árvore, k = qtd bolas que tem filhos , vRaiz = bola raíz;
    int vNo, vEsq, vDir;
    char l, ll;

    scanf ("%d%c%d%c%d", &nNos, &l, &nLinhas, &ll, &vRaiz); // lendo a primeira linha
    No *arvore = criarNo ( vRaiz ); // criu o primeiro nó
    Celula *lista = criarLista (); // criu a lista

    int j = 0;
    while ( j < nLinhas){
        int k = 0;
        scanf ("%d%c%d%c%d", &vNo, &l, &vEsq, &ll, &vDir);
        inserirNaLista (lista, vNo, vEsq, vDir);
    j++;
    }


    construirArvore ( arvore, lista);
    printf ("%d\n", 1 + altura ( arvore ));


    return 0;
}


