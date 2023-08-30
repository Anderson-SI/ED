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

// função que recebe um fila e retira o valor para criar um nó para inserir na árvore
No* criarNo (Celula *fila)
{
    No *novo = malloc ( sizeof ( No ));
    novo->dado = fila->prox->dado;
    novo->esq = novo->dir = NULL;
    fRemover ( fila );
    return novo;
}

// função que constróe a árvore
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

// função que devolve a altura da árvore
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

// função que devolve a quantidade de nós da árvore
int conta_no (No *raiz)
{
    if (raiz->dado == (-1)) { return 0; }
    else {
        int conte = conta_no ( raiz->esq );
        int conted = conta_no ( raiz->dir );
        return 1 + conte + conted;
    }
}

// imprime os nós que possuem apenas um filho
void nosComUmFilho ( No *raiz) // e-r-d
{
    if (raiz->dado != (-1)) {
        nosComUmFilho ( raiz->esq );
        if (raiz->esq->dado == (-1) && raiz->dir->dado != (-1)) {
                printf (" ", raiz->dado);
                printf ("%d", raiz->dado);
        }
        else if (raiz->esq->dado != (-1) && raiz->dir->dado == (-1)) {
                printf (" ", raiz->dado);
                printf ("%d", raiz->dado);
        }
        nosComUmFilho ( raiz->dir );
    }
}

// Função que verifica se a árvore é completa ou não
void completa ( No *raiz )
{
    int cn = conta_no ( raiz );
    int al = altura ( raiz );
    int res = pow (2, al) - 1;
    if (cn == res) {
        printf ("completa\n");
        printf ("total de nos: %d\n", cn);
    }
    else {
        printf ("nao completa\n");
        printf ("nos com um filho:");
        nosComUmFilho ( raiz );
        printf ("\n");
    }
}



int main ()
{

    // (7(13(0()())(1()()))(11(2()())(9()())))
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

    completa ( raiz );

    return 0;
}

