#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct no {
    int dado;
    struct no *prox;
} No;

No *criar ( void )
{
    No *novo = malloc (sizeof (No));
    novo->prox = NULL;
    return novo;
}

void inserir (int x, No *lista)
{
    No *n = malloc (sizeof ( No ));
    n->dado = x;
    No *p = lista;
    while (p->prox != NULL) { p = p->prox; }
    n->prox = p->prox;
    p->prox = n;
}

void imprimir (No *conjunto)
{
    if (conjunto->prox == NULL) {
        printf ("VAZIO\n");
    }
    else {
        No *p;
        for (p = conjunto->prox; p != NULL; p = p->prox)
        {
            printf ("%d\n", p->dado);
        }
    }
    printf ("\n");
}

int busca (int x, No *inters)
{
    No *j = inters->prox;
    while (j != NULL)
    {
        if (x == j->dado) {
            return 0;
        }
    j = j->prox;
    }
    return 1;
}


void buscaElemento (No *cUm, No *cDois,  No *cInters)
{
    No *p = cUm->prox;
    while  ( p != NULL )
    {
        No *j = cDois->prox;
        while (j != NULL )
        {
            if (p->dado == j->dado) {
                    if (busca (j->dado, cInters))
                    {
                        printf ("D = %d ", j->dado);
                        inserir ( p->dado, cInters );
                    }
            }
        j = j->prox;
        }
    p = p->prox;
    }
}

void troca (No *menor, No *maior)
{
    int m = menor->dado;
    menor->dado = maior->dado;
    maior->dado = m;

}

void ordena ( No *conjunto )
{
    if (conjunto->prox != NULL) {
        if ((conjunto->prox)->prox != NULL) {
            No *A = conjunto->prox;
            while (A->prox != NULL) {
                int f = 1;
                No *B = A->prox;
                while  (B != NULL)
                {
                    if (B->dado < A->dado)
                    {
                        troca ( A, B );
                    }
                    B = B->prox;
                }
            A = A->prox;
            }
        }
    }
}

void preencherConjunto (No *lista, No *lista2)
{
    int x;
    int i = 0;
    while (i < 20)
    {
        scanf ("%d", &x);
        inserir ( x, lista );
    i++;
    }
    i = 0;
    while (i < 20)
    {
        scanf ("%d", &x);
        inserir ( x, lista2 );
    i++;
    }
}

int main ()
{
    No *conjuntoUm = criar ();
    No *conjuntoDois = criar ();
    No *interseccao = criar ();

    preencherConjunto ( conjuntoUm , conjuntoDois );

    buscaElemento ( conjuntoUm , conjuntoDois, interseccao );

    ordena ( interseccao );

    imprimir ( interseccao );








    return 0;
}
