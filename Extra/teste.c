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

void troca (No *menor, No *maior)
{
    int m = menor->dado;
    menor->dado = maior->dado;
    maior->dado = m;

}

void ordena ( No *fila )
{
    if ((fila->prox)->prox != NULL) {
        No *A = fila->prox;
        while (A->prox != NULL) {
                int f = 1;
                No *B = A->prox;
                while  (B != NULL)
                {
                    if (B->dado > A->dado)
                    {
                        troca ( A, B );
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

int v (No *filaOriginal, No *fila)
{
    int cont = 0;
    No *pO = filaOriginal->prox;
    No *p = fila->prox;

    while (pO != NULL)
    {
        if (pO->dado == p->dado)
        {
            cont++;
        }
    pO = pO->prox;
    p = p->prox;
    }
    return cont;
}



int main ()
{


    No *fila = criar ();

    int k;
    scanf ( "%d", &k );

    while (k > 0)
    {
        No *fila = criar ();
        No *filaOriginal = criar ();

        int x, h;
        char c;
        scanf ("%d", &h);
        while( h > 0)
        {
            scanf("%d%c",&x, &c);
            inserir ( x, fila );
            inserir ( x, filaOriginal );
        h--;
        }

        ordena ( fila );

        int i = v (filaOriginal, fila);
        printf ("%d\n", i);


        k--;
    }




    /*
    inserir ( 500 , fila);
    inserir ( 200 , fila);
    inserir ( 300 , fila);
    inserir ( 400 , fila);
    inserir ( 100 , fila);

    printf (" --- Fila --- \n");
    imprimir ( fila );

    int i = ordena ( fila );

    printf (" --- Fila Ordenada --- \n");
    imprimir ( fila );
    printf ("qtd: %d\n", i);
    */







    return 0;
}
