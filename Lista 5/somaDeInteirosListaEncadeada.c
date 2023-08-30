#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct no {
    int dado;
    struct no *prox;
} No;

No *criar_l ( void )
{
    No *novo = malloc ( sizeof ( No ));
    novo->prox = NULL;
    return novo;
}

void inserir_final (int *x, No *le)
{
    No *novo = malloc (sizeof ( No ));
    novo->dado = *x;
    if ( le->prox == NULL) { novo->prox = le->prox; le->prox = novo; }
    else
    {
        No *aux = le->prox;
        while (aux->prox != NULL) { aux = aux->prox; }
        novo->prox = aux->prox;
        aux->prox = novo;
    }
}

void inserir_inicio ( int *x, No *le )
{
    No *novo = malloc (sizeof ( No ));
    novo->dado = *x;
    novo->prox = le->prox;
    le->prox = novo;
}

void imprimir ( No *le )
{
    if (le->prox != NULL)
    {
        No *aux = le->prox;
        while (aux->dado == 0)
        {
            aux = aux->prox;
        }
        while (aux->prox != NULL) {
            printf ( "%d ", aux->dado );
            aux = aux->prox;
        }
        printf ( "%d\n", aux->dado );
    }
}

void soma ( No *par1 , No *par2 , No *resul )
{
    if (par1->prox == NULL && par2->prox == NULL) { printf ( "Lista vazia!\n" ); }
    else
    {
        No *auxPar1, *auxPar2;
        auxPar2 = par2->prox;

        int s = 0;

        for (auxPar1 = par1->prox; auxPar1 != NULL; auxPar1 = auxPar1->prox ) {
            if (auxPar2 != NULL)
            {
                s = (s + auxPar1->dado + auxPar2->dado);
                if (s >= 10) { int r = s % 10; s = s / 10; inserir_inicio ( &r, resul ); }
                else { inserir_inicio ( &s, resul ); s = 0; }

                auxPar2 = auxPar2->prox;
            }
            else
            {
                s = (s + auxPar1->dado);
                if (s >= 10) { int r = s % 10; s = s / 10; inserir_inicio ( &r, resul ); }
                else { inserir_inicio ( &s, resul ); s = 0; }
            }
        }
        if (auxPar2 != NULL)
        {
            while (auxPar2 != NULL)
            {
                s = (s + auxPar2->dado);
                if (s >= 10) { int r = s % 10; s = s / 10; inserir_inicio ( &r, resul ); }
                else { inserir_inicio ( &s, resul ); s = 0; }

                auxPar2 = auxPar2->prox;
            }
        }
        if (s > 0) { inserir_inicio ( &s, resul ); }
        imprimir ( resul );
    }
}


int main ()
{
    int i;
    char c;

    No *parcela1 = criar_l ();
    No *parcela2 = criar_l ();
    No *resultado = criar_l ();

    while (scanf ("%d%c", &i, &c ) == 2) {
        inserir_inicio ( &i, parcela1 );
        if ( c == '\n') { break; }
    }

    scanf ("%c", &c);

    while (scanf ("%d%c", &i, &c ) == 2) {
        inserir_inicio ( &i, parcela2 );
        if ( c == '\n') { break; }
    }

    scanf ("%c", &c);

    if ( c == '=' )
    {
        soma ( parcela1 , parcela2, resultado );
    }



    return 0;
}






