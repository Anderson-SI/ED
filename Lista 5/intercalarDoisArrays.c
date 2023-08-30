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

void imprimir_ (No *array)
{
    No *p;
    for (p = array->prox; p != NULL; p = p->prox) {
        printf ("%d\n", p->dado);
    }
    liberar_ ( array );
}

// função que recebe uma Array e faz sua intercalação
void intercalar ( int *n, No *array )
{
    if (array != NULL)
    {
        int x = 0;
        No *lixo;

        No *cab = array->prox;
        No *aux = array->prox;

        while (x  < *n) { aux = aux->prox; x++; }

        while (aux->prox != NULL)
        {

            No *novo = malloc (sizeof (No));
            novo->dado = aux->dado;
            novo->prox =  cab->prox;

            cab->prox = novo;
            cab = (cab->prox)->prox;

            lixo = aux;
            aux = aux->prox;
            free(lixo);
        }
        cab->prox = aux;
        free(aux);
    }
}

void preencher ( int *n, No *array )
{
    int x;
    int k = 0;
    for (int *pk = &k; *pk <  2 * (*n); (*pk)++)
    {
        scanf ("%d", &x );
        inserir_final ( &x, array );
    }
}

int main ()
{

    No *array;
    array = criar_ ();

    int n;
    scanf ("%d", &n);

    preencher ( &n, array );

    intercalar ( &n, array );

    imprimir_ ( array );




    return 0;
}
