#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct no {
    int chave;
    struct no *prox;
} No;

No *criar ( void )
{
    No *n = malloc ( sizeof ( No ));
    n->prox = NULL;
    return n;
}

// função hash que devolve o resto da divisão da chave pelo tamanho da coluna
int hash (int ch, int *m)
{
    return (ch % *m);
}

// Função para verificar
int verificar (No *l, int ch, int *c)
{
    No *p = l->prox;
    if (p == NULL) { return 0; }
    else {
        while (p != NULL)
        {
            *c = *c + 1;
            if (p->chave == ch)
            {
                return 1;
            }
        p = p->prox;
        }
    }
    return 0;
}

// função para adicionar
void add (No *l, int ch)
{

    No *n = malloc ( sizeof ( No ));
    n->chave = ch;
    n->prox = l->prox;
    l->prox = n;
}

int fAdd (No *l, int ch, int *c)
{
    int r = verificar ( l , ch, c);
    if (r) { return 0; }
    else {
        add ( l, ch );
    }
    return 1;
}

// função para imprimir
void imprimir (No *tb)
{
    No *p = tb->prox;
    if (p == NULL) { printf (" V = "); }
    else {
        while (p != NULL) {
        printf ("%d ", p->chave);
        p = p->prox;
        }
    }
    printf ("\n");
}

int fCarga (float n, int *m)
{
    if (n / (*m) >= 0.75) { return 1; }
    else { return 0; }
}

int del (No *tb, int ch) {
    No *aux = tb;
    No *p = tb->prox;
    if (p != NULL) {
        while (p != NULL && p->chave != ch) {
            p = p->prox;
            aux = aux->prox;
        }
        if (p != NULL) {
            aux->prox = p->prox;
            free (p);
            return 1;
        }
    }
    return 0;
}

int remover (No *l, int ch, int *m, int *c)
{
    verificar ( l, ch , c );
    int j = del ( l, ch );
    if (j) { return 1; }
    else { return 0; }
}



No **criarTb (int *m)
{
    No **tb = malloc ( (*m) * sizeof ( No ) );
    for (int j = 0; j < *m; j++)
    {
        *(tb + j) = criar ();
    }
    return tb;
}

void liberar ( No *lista )
{
    if (lista != NULL) {
        No *lixo;
        while (lista != NULL) {
            lixo = lista;
            lista = lista->prox;
            free (lixo);
        }
    }
}



No **realocacao (No **tb, int *m )
{
    int mm = *m;
    *m = (2 * (*m)) - 1;
    No **tabela = malloc ((*m) * sizeof ( No ));
    for (int j = 0; j < *m; j++)
    {
        *(tabela + j) = criar ();
    }
    for (int j = 0; j < mm; j++)
    {
        No *p = *(tb + j);
        p = p->prox;
        while (p != NULL) {
            int h = hash ( p->chave , m );
            add ( *(tabela + h), p->chave );
        p = p->prox;
        }
    }
    for (int k = 0; k < mm; k++)
    {
        No *p = *(tb + k);
        liberar ( p );
    }
    free ( tb );

    return tabela;
}


int has (No *l, int ch, int *c)
{
    verificar ( l, ch , c );
    No *p = l->prox;
    while (p != NULL)
    {
        if (p->chave == ch ) { return 1; }
    p = p->prox;
    }
    return 0;
}

int contador (int *pm, No **tb) {
    int n = 0;
    for (int j = 0; j < *pm; j++)
    {
        No *lista = *(tb + j);
        if (lista->prox != NULL) { n++; }
    }
    return n;
}

int maiorConjunto (No  **tb, int *pm)
{
    int k = 0;
    for (int h = 0; h < (*pm); h++)
    {
        No *lis = *(tb + h);
        No *p = lis->prox;
        int f = 0;
        while (p != NULL) {
            f++;
        p = p->prox;
        }
        if (f > k) { k = f; }
    }
    return k;
}



int main ()
{
    char op[4];
    char car;
    int m = 7;
    int *pm = &m;
    int i = 0, r, l, k;
    float n;


    No **tb = criarTb ( pm );

    while (1)
    {
        scanf ("%s", &op);
        int c = 0;

        if (strcmp ( op, "ADD" ) == 0)
        {
            scanf ("%c%d", &car, &k);
            int h = hash ( k, pm );
            No *lista = *(tb + h);
            r = fAdd ( lista , k, &c);

            printf ("%d %d %d\n", i, r, c);

            int n = contador ( pm,  tb);
            if (fCarga ( n, pm )) {
                tb = realocacao ( tb, pm );
            }

            for (int j = 0; j < (*pm); j++)
            {
                No *p = *(tb + j);
                imprimir ( p );
            }


        }
        else if (strcmp ( op, "DEL" ) == 0)
        {
            scanf ("%c%d", &car, &k);
            int h = hash ( k, pm );
            No *p = *(tb + h);
            r = remover ( p, k, pm, &c);
            printf ("%d %d %d\n", i, r, c);
        }
        else if (strcmp ( op, "HAS" ) == 0)
        {
            scanf ("%c%d", &car, &k);
            int h = hash ( k, pm );
            No *p = *(tb + h);
            r = has ( p, k, &c);
            printf ("%d %d %d\n", i, r, c);

        }
        else if (strcmp ( op, "PRT" ) == 0)
        {
            int n = contador ( pm,  tb);
            int l = maiorConjunto ( tb, pm);
            printf ("%d %d %d %d\n", i, *pm, n, l);
        }
    i++;
    }




    return 0;
}


