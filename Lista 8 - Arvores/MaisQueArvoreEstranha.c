#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// estrutura lista
typedef struct celula {
    int slr[3]; // s = Bola Filha; l = bola Filha esquerda; r = bola Filha direita.
    struct celula *prox;
} Celula;

Celula* criarLista ( void )
{
    Celula *n = malloc ( sizeof ( Celula ));
    n->prox = NULL;
    return n;
}

void inserirNaLista (Celula *lis, int s, int l, int r)
{
    Celula *novo = malloc ( sizeof ( Celula ));
    novo->slr[0] = s; novo->slr[1] = l; novo->slr[2] = r;
    novo->prox = lis->prox;
    lis->prox = novo;
}

void imprimirLista (Celula *lis)
{
    Celula *p;
    for (p = lis->prox; p != NULL; p = p->prox) {
        printf ("%d %d %d\n", p->slr[0], p->slr[1], p->slr[2]);
    }
}

void fRemoverCelulaLista ( Celula *lista, Celula *cel )
{
    Celula *lixo;
    if (lista->prox != NULL) {
        Celula *pp = lista->prox;
        Celula *pa = lista;
        while (pp != cel) { pp = pp->prox; pa = pa->prox; }
        lixo = pp;
        pa->prox = lixo->prox;
        free(lixo);
    }
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

void construirArvore (No *raiz, Celula *celula, Celula *lista)
{
    if (raiz != NULL && raiz->dado != (-1)) {
        construirArvore ( raiz->esq , celula, lista );
        if (raiz->dado == celula->slr[0])
        {
            raiz->esq = criarNo (celula->slr[1]);
            raiz->dir = criarNo (celula->slr[2]);
            fRemoverCelulaLista (lista, celula);
        }
        construirArvore ( raiz->dir , celula, lista );
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

    int n, k, vRaiz; // n = qtd de nós na árvore, k = qtd bolas que tem filhos , vRaiz = bola raíz;
    int s, es, di;
    char l, ll;

    scanf ("%d%c%d%c%d", &n, &l, &k, &ll, &vRaiz);

    Celula *lista = criarLista ();
    No *arvore = criarNo ( vRaiz );


    // armazenando os valores em uma lista
    for (int i = 0; i < k; i++)
    {
        scanf ("%d%c%d%c%d", &s, &l, &es, &ll, &di);
        inserirNaLista (lista, s, es, di);
    }

    // Construindo a árvore
    for (int i = 0; i < n; i++) {
        Celula *celula = lista->prox;
        while (celula != NULL) {
            construirArvore ( arvore, celula, lista);
        celula = celula->prox;
        }
    }

    printf ("%d\n", 1 + altura ( arvore ));








    return 0;
}

