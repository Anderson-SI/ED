#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct no {
    int chave;
    struct no *prox;
} No;

No *criar ( void )
{
    No *n = malloc ( sizeof ( No ));
    n->prox = NULL;
    return n;
}

// função inserir, insere os elementos em de forma ordenada
void inserir (No *tb, int ch) // insere de forma ordenada
{
    No *n = malloc (sizeof ( No ));
    n->chave = ch;
    if (tb->prox == NULL) {
        n->prox = tb->prox;
        tb->prox = n;
    } else {
        No *aux = tb;
        No *p = tb->prox;
        while (p != NULL && p->chave <= ch)
        {
            p = p->prox;
            aux = aux->prox;
        }
        if (p == NULL) {
            n->prox = p;
            aux->prox = n;
        } else {
            n->prox = p;
            aux->prox = n;
        }
    }
}

// função hash dada uma chave devolve o resto da divisão da chave pelo tamanho da tabela
int hash (int ch, int *m)
{
    return ch % *m;
}

// função imprimi
void imprimir ( No *tb )
{
    No *p = tb->prox;
    if (p == NULL) { printf ("Lista vazia!"); }
    else {
        while (p != NULL)
        {
            printf ("%d=>", p->chave);
        p = p->prox;
        }
    }
    printf ("\n");
}

// função para contar o número de elementos em uma lista encadeada
void contador (No *tb, int *cont)
{
    No *aux = tb->prox;
    while (aux != NULL) { *cont = *cont + 1; aux = aux->prox; }
}

int buscarElemento (No **tb, int ch, int *m, int *e)
{
    int r = 0;
    int h = hash ( ch, m );
    No *pp = *(tb + h);
    No *p = pp->prox;
    if (p == NULL) { return r; }
    else {
        while (p != NULL && p->chave != ch) {
            *e = *e + 1;
            p = p->prox;
        }
        if (p != NULL && p->chave == ch) { *e = *e + 1; r++; }
    }
    return r;

}

void removeElemento (No **tb, int ch, int *m) {
    int h = hash ( ch, m );
    No *pp = *(tb + h);
    No *aux = pp;
    No *p = pp->prox;
    if (p != NULL) {
        while (p != NULL && p->chave != ch) {
            p = p->prox;
            aux = aux->prox;
        }
        if (p != NULL) {
            aux->prox = p->prox;
            free (p);
        }
    }
}

int main ()
{

    int m;
    scanf ("%d", &m);

    No **tabela = malloc (m * sizeof ( No ));
    for (int j = 0; j < m; j++) {
        *(tabela + j) = criar ();
    }

    int ch;
    char g, esc;

    while (1) {
        scanf ("%c", &g);
        if (g == 'f') { break; }
        else if (g == 'a')
        {// inserir
            scanf ("%c%d", &esc, &ch);
            int h = hash ( ch, &m );
            No *pLis = *(tabela + h);
            inserir ( pLis, ch);
        }
        else if (g == 'i')
        {// imprimir
            printf ("imprimindo tabela hash:\n");
            for (int k = 0; k < m; k++) {
                No *pLis = *(tabela + k);
                printf ("[%d]:", k);
                imprimir ( pLis );
            }
        }
        else if (g == 'r')
        { // remover
            scanf ("%c%d", &esc, &ch);
            removeElemento ( tabela, ch, &m);

        }
        else if (g == 'p')
        {// buscar

            int cont = 0;
            int num = 0;
            int numEle = 0;

            scanf ("%c%d", &esc, &ch);
            printf ("BUSCA POR %d\n", ch);

            for (int l = 0; l < m; l++) {
                contador ( *(tabela + l) , &cont );
            }
            printf ("numero de elementos da tabela hash: %d\n", cont);

            int j = buscarElemento ( tabela, ch, &m, &numEle);
            if (j) { printf ("elemento %d encontrado!\n", ch); }
            else { printf ("elemento nao encontrado!\n"); }
            printf ("numero de elementos acessados na tabela hash: %d\n", numEle);

        }
    }

    return 0;
}


