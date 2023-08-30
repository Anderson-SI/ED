#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct no {
    int dado;
    int maior;
    int menor;
    struct no *prox;
} No;

No *criar_p (void)
{
    No *novo = malloc (sizeof (No));
    novo->prox = NULL;
    return novo;
}

void push (int x, No *pi)
{
    No *novo = malloc (sizeof (No));
    novo->dado = x;
    if (pi->prox == NULL) {

        pi->maior = x;
        pi->menor = x;

        novo->prox = pi->prox;
        pi->prox = novo;

    } else {
        if (x < pi->menor) { pi->menor = x; }
        if (x > pi->maior) { pi->maior = x; }
        No *aux;
        aux = pi->prox;
        pi->prox = novo;
        novo->prox = aux;
    }
}


void desempilhar (No *pi)
{
    if (pi->prox != NULL)
    {
        No *lixo;
        lixo = pi->prox;
        pi->prox = lixo->prox;
        free (lixo);
    }
}

void pop ( No *pi )
{
    if (pi->prox != NULL)
    {
        No *aux = pi->prox;
        int k = aux->dado;
        printf ("%d\n", aux->dado);
        desempilhar ( pi );

        if (k == pi->menor)
        {
            No *p = pi->prox;
            k = pi->maior;
            while (p != NULL)
            {
                if (p->dado < k) { k = p->dado; }
                p = p->prox;
            }
            pi->menor = k;
        }
        if (k == pi->maior)
        {
            No *p = pi->prox;
            k = pi->menor;
            while (p != NULL)
            {
                if (p->dado > k) { k = p->dado; }
                p = p->prox;
            }
            pi->maior = k;
        }
    }
}


void valorAbsoluto (No *pilha)
{
    printf ("%d\n", abs ((pilha->maior) - (pilha->menor)));
}

int main ()
{

    char str[5];
    int i;
    No *pi = criar_p ();

    while (scanf ("%s", &str) == 1) {
            if ( !strcmp (str, "push") )
            {
                scanf ("%d", &i);
                push ( i, pi );
            }
            else if (!strcmp (str, "pop"))
            {
                pop ( pi );
            }
            else if (!strcmp (str, "abs"))
            {
                valorAbsoluto ( pi );
            }
    }

    return 0;
}




