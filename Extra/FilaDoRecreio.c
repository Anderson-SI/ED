#include <stdio.h>
#include <stdlib.h>


typedef struct no
{
    int dado;
    struct no *prox;
} No;

No * criar ( void )
{
    No *novo = malloc ( sizeof ( No ));
    novo->prox = NULL;
    return novo;
}

void inserir (int x, No *fila)
{
    No *novo = malloc (sizeof (No));
    novo->dado = x;
    novo->prox = NULL;
    if (fila == NULL) { fila->prox = novo; }
    else {
        No *aux = fila;
        while (aux->prox != NULL) { aux = aux->prox; }
        aux->prox = novo;
    }
}

No *devolveAnt ( int x, No * fila )
{
    No *p = fila;
    if (p->prox == NULL) { return NULL; }
    else if ((p->prox)->prox == NULL) { return p;}
    else
    {
        while ((p->prox)->prox != NULL && (p->prox)->dado != x)
        {
            p = p->prox;
        }
        if ((p->prox)->dado == x) { return p;}
    }
    return NULL;
}

void troca (No *A, No *B, No *fila)
{
    No *pA = devolveAnt ( A->dado, fila );
    No *pB = devolveAnt ( B->dado, fila );

    No *ref = B->prox;

    if ( pB == A)
    {
        A->prox = ref;
        B->prox = A;
        pA->prox = B;
    }
    else
    {
        B->prox = A->prox;
        pA->prox = B;
        pB->prox = A;
        A->prox = ref;
    }
}

int ordena ( No *fila )
{
    int cont = 0;
    if (fila->prox == NULL) { return cont; }
    else if ((fila->prox)->prox == NULL) { return ++cont; }
    else
    {
        No *A = fila->prox;
        while (A->prox != NULL) {
                No *B = A->prox;
                while  (B->prox != NULL)
                {
                    if (B->dado > A->dado)
                    {
                        troca (A, B, fila);
                    }
                    B = B->prox;
                }
        A = A->prox;
        }
    }
}






void imprimir ( No *fila )
{
    No *p;
    for (p = fila->prox; p != NULL; p = p->prox) {
        printf ( "%d ", p->dado );
    }
    printf ("\n");
}


int main ()
{

    /*
    int k;
    scanf ( "%d", &k );
    while (k > 0)
    {
        No *fila = criar ();

        int x;
        char c;
        while(scanf("%d%c",&x, &c) == 2)
        {
            inserir ( &x, fila );
            if (c == '\n') { break; }
        }
        k--;
    */

    No *fila = criar ();

    inserir ( 100 , fila);
    inserir ( 200 , fila);
    inserir ( 300 , fila);
    inserir ( 400 , fila);
    inserir ( 500 , fila);

    printf (" --- Fila --- \n");
    imprimir ( fila );

    No *pk = fila;

    No *A = pk->prox;
    No *B = (pk->prox)->prox;
    No *C = ((pk->prox)->prox)->prox;

    printf ("\n --- Enderecos antes da troca --- \n");
    printf ("A = %0x, ", A);
    printf ("B = %0x, ", B);
    printf ("C = %0x \n", C);

    printf ("\n --- funcao Ordena --- \n");
    //troca (B, C, fila );
    int i = ordena ( fila );
    printf ("i = %d\n", i);

    printf (" \n--- Fila --- \n");
    imprimir ( fila );

    printf ("\n --- Enderecos depois da troca --- \n");
    printf ("A = %0x, ", A);
    printf ("B = %0x, ", B);
    printf ("C = %0x \n", C);

    return 0;
}
