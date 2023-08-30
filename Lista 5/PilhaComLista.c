#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct nol {
    int dado;
    struct nol *prox;
} Lista;

Lista *criar_lista (void)
{
    Lista *novo = malloc ( sizeof (Lista ));
    novo->prox = NULL;
    return novo;
}

// função que insere dados na lista
void inserir_lista (int *x, Lista *lis)
{
    Lista *novo = malloc (sizeof ( Lista ));
    novo->dado = *x;

    if (lis->prox == NULL) { novo->prox = lis->prox; lis->prox = novo; }
    else
    {
        Lista *aux = lis;
        while (aux->prox != NULL) { aux = aux->prox; }
        novo->prox = aux->prox;
        aux->prox = novo;
    }
}

// função que imprime os elementos da lista
void imprime (Lista *lis)
{
    Lista *p;
    for (p = lis->prox; p->prox != NULL; p = p->prox) {
        printf ("%d ", p->dado);
    }
    printf ("%d\n", p->dado);
}

typedef struct nop {
    Lista *lis;
    struct nop *prox;
} NoP;

NoP *criar_p (void)
{
    NoP *novo = malloc (sizeof (NoP));
    novo->prox = NULL;
    return novo;
}

void push (Lista *lis, NoP *pi)
{
    NoP *novo = malloc (sizeof ( NoP ));
    novo->lis = lis;
    novo->prox = pi->prox;
    pi->prox = novo;
}

// liberar lista
void liberar_lista (Lista *lis)
{
    if (lis != NULL) {
        Lista *lixo;
        while (lis != NULL) {
            lixo = lis;
            lis = lis->prox;
            free (lixo);
        }
    }
}

// função desempilhar usada na função pop
void desempilhar (NoP *pi)
{
    if (pi->prox != NULL)
    {
        NoP *lixo;
        lixo = pi->prox;
        pi->prox = lixo->prox;
        liberar_lista ( lixo->lis );
        free (lixo);
    }
}

void pop ( NoP *pi )
{
    if (pi->prox != NULL)
    {
        NoP *p = pi->prox;
        imprime ( p->lis );
        desempilhar ( pi );
    }
    else
    {
        printf ("EMPTY STACK\n");
    }
}





int main ()
{

    char str[5];
    int i;
    NoP *pi = criar_p ();

    while (scanf ("%s", &str) == 1) {
            if ( !strcmp (str, "PUSH") )
            {
                int n;
                char c;
                Lista *l = criar_lista ();
                while (scanf ("%d%c", &n, &c) == 2 && c != '\n') {
                    inserir_lista ( &n, l );
                }
                inserir_lista ( &n, l );
                push ( l , pi );
            }
            else if (!strcmp (str, "POP"))
            {
                pop ( pi );
            }
    }

    return 0;
}





