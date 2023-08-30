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

void inserir (int x, No *est)
{
    No *novo = malloc (sizeof ( No ));
    novo->dado = x;
    No *p = est->prox;
    est->prox = novo;
    novo->prox = p;
}

int removerPilha (int x, No *est)
{
    if (est->prox != NULL)
    {
        No *lixo;
        lixo = est->prox;
        if (lixo->dado == x) {
            est->prox = lixo->prox;
            free (lixo);
            return 1;
        }
    }
    return 0;
}

void removerMeio (int x, No *est)
{
    No *lixo;
    No *ant = est;
    if ((est->prox)->prox == NULL)
    {
        lixo = est->prox;
        est->prox = lixo->prox;
        free (lixo);
    }
    else {
        lixo = est->prox;
        while (lixo->prox != NULL) { lixo = lixo->prox; ant = ant->prox; }
            if (lixo->dado == x)
            {
                ant->prox = lixo->prox;
                free(lixo);
            }
    }
}


int removerFila (int x, No *est)
{
    No *lixo;
    No *ant = est;
    if (est->prox != NULL) {
        lixo = est->prox;
        while (lixo->prox != NULL) { lixo = lixo->prox; ant = ant->prox; }
        if (lixo->dado == x)
        {
            ant->prox = lixo->prox;
            free(lixo);
            return 1;
        }
    }
    return 0;
}

void liberar_ (No *est)
{
    if (est != NULL) {
        No *lixo;
        while (est !=  NULL) {
            lixo = est;
            est = lixo->prox;
            free (lixo);
        }
        free ( est );
    }
}

int verificar (int x, No *est)
{

    if (est->prox != NULL)
    {
        int t = (est->prox)->dado;
        No *aux = est;
        while (aux->prox != NULL) { aux = aux->prox; }
        if (t == x && aux->dado == x) { return 1; }
    }
    return 0;
}


void retorna ( char s[], int x, No *est)
{
    if ((est->prox)->prox == NULL) {
        if ((est->prox)->dado == x) { strcpy ( s , "ambas"); int i = removerPilha (x, est); }
    }
    else
    {
        if (verificar ( x, est )!= 1) {
            if ( removerFila ( x, est)) { strcpy ( s , "fila"); }
            else if ( removerPilha (x, est)) { strcpy ( s , "pilha"); }
            else { removerMeio ( x, est); strcpy ( s , "nenhuma"); }
        }
    }
}

void imprimir (No *fila)
{
    No *p;
    for (p = fila->prox; p != NULL; p = p->prox) {
        printf ("%d \n", p->dado);
    }
}

int main ()
{
    int t, caso = 1;
    scanf ("%d", &t);

    while ( caso <= t)
    {
        char ss[8] = "ambas";
        No *estrutura = criar ();
        int n;
        scanf ("%d", &n);
        int flag = 0;
        while  ( n > 0)
        {
            int x, i;
            char c;
            scanf ("%d%c%d", &i, &c, &x);

            if (i == 1)
            {
                inserir ( x, estrutura );
            }
            else if (i == 2)
            {
                if (flag == 0) {
                    retorna ( ss, x, estrutura );
                    flag = 1;
                }
            }
        n--;
        }

        printf ("caso %d: %s\n" , caso, ss );

        liberar_ ( estrutura ); //removo todos os elementos da estrutura
    caso++;
    }

    return 0;
}

