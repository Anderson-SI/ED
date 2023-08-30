#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int dado;
    struct no *prox;
} No;

No *criar_f ( void )
{
    No *novo = malloc ( sizeof ( No ));
    novo->prox = NULL;
    return novo;
}

void inserir (int *i, No *fila)
{
    No *novo = malloc (sizeof ( No ));
    novo->dado = *i;
    if ( fila->prox == NULL) { novo->prox = fila->prox; fila->prox = novo; }
    else
    {
        No *aux = fila;
        while ( aux->prox != NULL) { aux = aux->prox; }
        novo->prox = aux->prox;
        aux->prox = novo;
    }
}

void remover (int *i, No *fila)
{
    if (fila->prox != NULL)
    {
        No *an, *at;
        an = fila;
        at = fila->prox;

        while (at != NULL && at->dado != *i) { at = at->prox; an = an->prox; }

        if (at == NULL) { printf ("falha\n"); }
        else { // (at->dado == *i)
            an->prox = at->prox;
            free ( at );
            printf ("removido\n");
        }
    }
    else { printf ("falha\n"); }
}

void imprimir ( No *fila )
{
    if (fila->prox == NULL) { printf ("vazia\n");}
    else
    {   No *p;
        for ( p = fila->prox; p->prox != NULL; p = p->prox) { printf ("%d ", p->dado); }
        printf ("%d\n", p->dado);
    }
}

int main ()
{

    No *fila = criar_f ();
    char c;
    int i;
    while (scanf ("%c", &c) == 1)
    {
        if (c == 'a')
        {
            scanf ("%d", &i);
            inserir ( &i, fila);
        }
        else if (c == 'p')
        {
            imprimir ( fila );
        }
        else if (c == 'r')
        {
            scanf ("%d", &i);
            remover ( &i, fila );
        }
        else if (c == 's')
        {
            break;
        }
    }

    return 0;
}
