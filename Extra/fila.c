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

void enfileirar (int x, No *fila)
{
    No *n = malloc (sizeof ( No ));
    n->dado = x;
    No *p = fila;
    while (p->prox != NULL) { p = p->prox; }
    n->prox = p->prox;
    p->prox = n;
}

void desenfileirar (No *fila)
{
    No *lixo;
    if (fila->prox != NULL)
    {
        lixo = fila->prox;
        fila->prox = lixo->prox;
        free ( lixo );
    }
}


void imprimir (No *fila)
{
    No *p;
    for (p = fila->prox; p->prox != NULL; p = p->prox)
    {
        printf ("%d ", p->dado);
    }
    printf ("%d\n", p->dado);
}


int main ()
{

    char s[14];
    int i;

    No *fila = criar ();

    scanf ("%s", s);
    while (strcmp (s, "Finalizar") != 0) {
        if ( strcmp (s, "Enfileirar") == 0)
        {
            scanf ("%d", &i);
            enfileirar ( i ,fila );
        }
        else if (strcmp (s, "Imprimir") == 0)
        {
            imprimir ( fila );
        }
        else if (strcmp (s, "Desenfileirar") == 0)
        {
            desenfileirar ( fila );
        }

    scanf ("%s", s);
    }




    return 0;
}
