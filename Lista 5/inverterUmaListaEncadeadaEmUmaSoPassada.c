#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;
} No;

No* criar_ (void)
{
    No *cabeca = malloc (sizeof (No));
    cabeca->prox = NULL;
    return cabeca;
}

void inserir_final (int *x, No *lis)
{
    No *novo = malloc (sizeof (No));
    novo->dado = *x;
    novo->prox = NULL;
    if (lis == NULL) { lis->prox = novo; }
    else {
        No *aux;
        aux = lis;
        while (aux->prox != NULL) { aux = aux->prox; }
        aux->prox = novo;
    }
}


void liberar_ (No *array)
{
    if (array != NULL) {
        No *lixo;
        while (array !=  NULL) {
            lixo = array;
            array = lixo->prox;
            free (lixo);
        }
        free ( array );
    }
}

void inverter ( No *array )
{
    if (array->prox != NULL) {

        No *aux, *auxFim, *auxProx;

        auxFim = NULL;
        auxProx = array->prox;

        while (auxProx != NULL) {

            aux = auxProx->prox;
            auxProx->prox = auxFim;

            auxFim = auxProx;
            auxProx = aux;
        }
    array->prox = auxFim;
    }
}


void imprimir_ ( No *array )
{
    No *p;
    for (p = array->prox; p->prox != NULL; p = p->prox) {
        printf ("%d ", p->dado);
    }
    printf ("%d\n", p->dado);
    liberar_ ( array );
}

int main ()
{
    No *array = criar_ ();

    int i;
    char enter;
    while (scanf ("%d%c", &i, &enter) == 2) {
        inserir_final ( &i , array );
        if (enter == '\n') { break; }
    }

    inverter ( array );

    imprimir_ ( array );


    return 0;
}
