
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int dado;
    struct no *prox;
} No;

No *criar ( void )
{
    No *novo = malloc ( sizeof ( No ));
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

void removerPilha (No *pilha)
{
    if (pilha->prox != NULL)
    {
        No *lixo;
        lixo = pilha->prox;
        pilha->prox = lixo->prox;
        free (lixo);
    }
}

void removerFila ( No *fila)
{
    No *lixo;
    No *ant = fila;
    if (fila->prox != NULL) {
        lixo = fila->prox;
        while (lixo->prox != NULL) { lixo = lixo->prox; ant = ant->prox; }
        ant->prox = lixo->prox;
        free(lixo);
    }
}

// verifica se realmente é uma fila
int vFila (int x, No *est)
{
    if (est->prox != NULL) {
        No *p = est->prox;
        while (p->prox != NULL) { p = p->prox; }
        if (p->dado == x) { return 1; }
    }
    return 0;
}

// verifica se realmente é uma pilha
int vPilha (int x, No *est)
{
    if (est->prox != NULL) {
        No *p = est->prox;
        if (p->dado == x) { return 1; }
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

void ffila (char *s, int x , No *pilha)
{
    int f = vFila ( x, pilha );
    if (f == 1) { removerFila ( pilha ); }
    else {strcpy ( s, "nenhuma"); }
}

void fpilha (char *s, int x , No *pilha)
{
    int p = vPilha ( x, pilha );
    if (p == 1) { removerPilha ( pilha ); }
    else { strcpy ( s, "nenhuma"); }
}

void fambas (char *s, int x , No *pilha)
{
    int p = vPilha ( x, pilha );
    int f = vFila (x, pilha );

    if (f == 1) { removerFila ( pilha ); }
    else if (p == 1) { removerPilha (pilha); }
    else {strcpy ( s, "nenhuma"); }

}

void decidir ( char *s, int x, No *pilha ) {

    No *apE = pilha->prox;
    int p = vPilha (x , pilha);
    int f = vFila (x, pilha);

    if (p == 1 && f == 1) { strcpy ( s, "ambas"); removerPilha ( pilha );}
    else if (p == 1 && f != 1) { strcpy ( s, "pilha"); removerPilha ( pilha );}
    else if (p != 1 && f == 1) { strcpy ( s, "fila"); removerFila ( pilha );}
    else { strcpy ( s, "nenhuma"); }
}


int main ()
{
    // quantidade de casos
    int t, caso = 1;
    scanf ("%d", &t);

    // casos
    while ( caso <= t)
    {

        No *pilha = criar ();
        char s[8] = "";

        int n;
        scanf ("%d", &n);

        while  ( n > 0)
        {
            int x, i; char c; // artifício para lê os dados da forma correta
            scanf ("%d%c%d", &i, &c, &x);

            if (i == 1)
            {
                inserir ( x, pilha );
            }
            else if (i == 2)
            {
                if (strcmp ( s , "") == 0) {
                    decidir ( s, x, pilha );
                }
                else if (strcmp ( s , "ambas") == 0) {
                    fambas (s, x , pilha );
                }
                else if (strcmp ( s , "fila") == 0) {
                    ffila (s, x , pilha );
                }
                else if (strcmp ( s , "pilha") == 0) {
                    fpilha (s, x, pilha );
                }
            }
        n--;
        }

        if (strcmp ( s , "") == 0 && (pilha->prox) != NULL) {strcpy ( s, "ambas"); }

        printf ("caso %d: %s\n", caso, s);

        // depois de imprimir libero a estrutura da memória
        liberar_ ( pilha );

    caso++;
    }

    return 0;
}
