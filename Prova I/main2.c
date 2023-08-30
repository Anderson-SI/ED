#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    long int dado;
    struct no *prox;
} No;

No *criar ( void )
{
    No *novo = malloc (sizeof (No));
    novo->prox = NULL;
    return novo;
}

void inserir (long int x, No *est)
{
    No *novo = malloc (sizeof ( No ));
    novo->dado = x;
    No *p = est->prox;
    est->prox = novo;
    novo->prox = p;
}

void removerPilha (No *est)
{
    if (est->prox != NULL)
    {
        No *lixo;
        lixo = est->prox;
        est->prox = lixo->prox;
        free (lixo);
    }
}

void removerFila (No *est)
{
    No *lixo;
    No *ant = est;
    if (est->prox != NULL) {
        lixo = est->prox;
        while (lixo->prox != NULL) { lixo = lixo->prox; ant = ant->prox; }
        ant->prox = lixo->prox;
        free(lixo);
    }
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

int vFila (long int x, No *est)
{
    if (est->prox != NULL) {
        No *p = est->prox;
        while (p->prox != NULL) { p = p->prox; }
        if (p->dado == x) { return 1; }
    }
    return 0;
}

int vPilha (long int x, No *est)
{
    if (est->prox != NULL) {
        No *p = est->prox;
        if (p->dado == x) { return 1; }
    }
    return 0;
}


void retorna ( char s[], long int x, No *est)
{
    int f = vFila (x , est);
    int p = vPilha (x , est);
    if ( strcmp ( s , "ambas") == 0) {
        if (f == 1 && p == 0){ strcpy (s , "fila"); removerFila ( est );}
        else if (f == 0 && p == 1){ strcpy (s , "pilha"); removerPilha ( est ); }
        else if (f == 1 && p == 1){ removerPilha ( est ); }
        else if (f == 0 && p == 0){ strcpy ( s , "nenhuma"); }
    }
    else {
        if (strcmp ( s , "nenhuma") != 0) {
            if (strcmp ( s , "pilha") == 0 && p == 1 && f != 1)      { removerPilha ( est ); }
            else if (strcmp ( s , "fila") == 0 && p != 1 && f == 1)  { removerFila ( est ); }
            else if ( strcmp ( s , "fila") == 0 && p == 1 && f == 1) { strcpy ( s , "ambas"); removerFila ( est ); }
            else if ( strcmp ( s , "pilha") == 0 && p == 1 && f == 1){ strcpy ( s , "ambas"); removerPilha ( est ); }
            else if ( p == 0 && f == 0) { strcpy ( s , "nenhuma"); };
        }
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

        while  ( n > 0)
        {
            long int x;
            int i; char c;
            scanf ("%d%c%ld", &i, &c, &x);

            if (i == 1)
            {
                inserir ( x, estrutura );
            }
            else if (i == 2)
            {
                retorna ( ss, x, estrutura );
            }
        n--;
        }

        printf ("caso %d: %s\n" , caso, ss );

        liberar_ ( estrutura );
    caso++;
    }

    return 0;
}


