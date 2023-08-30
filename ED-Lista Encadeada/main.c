#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int conteudo;
    struct reg *prox;
} Celula;

Celula *criar (void)
{
    Celula *cabeca = malloc (sizeof (Celula));
    cabeca->prox = NULL;
    return cabeca;
}

void inserir (int x, Celula *le)
{
    Celula *nova = malloc (sizeof (Celula));
    nova->conteudo = x;
    nova->prox = le->prox;
    le->prox = nova;
}

void liberar_lista (Celula *le)
{
    if (le != NULL) {
        Celula *lixo;
        while (le != NULL) {
            lixo = le;
            le = le->prox;
            free (lixo);
        }
        free (le);
    }
}


void imprime (Celula *le)
{
    Celula *p;
    for (p = le->prox; p != NULL; p = p->prox)
        printf ("%d->", p->conteudo);
    printf ("NULL\n");
}

void remove_ (Celula *p)
{
    Celula *lixo;
    lixo = p->prox;
    p->prox = lixo->prox;
    free (lixo);
}


Celula* busca (int x, Celula *le)
{
    Celula *p;
    p = le;
    while (p != NULL && p->conteudo != x) {
        p = p->prox;
    }
    return p;
}

// conta o tamanho da minha lista
int tamanho (Celula *le)
{
    int cont = 0;
    Celula *p;
    p = le;
    while (p != NULL) {
        cont++;
        p = p->prox;
    }
    return cont;
}

void insere_final (int x, Celula *le)
{
    Celula *nova = malloc (sizeof (Celula));
    nova->conteudo = x;
    nova->prox = NULL;
    if (le->prox == NULL) {
        le = nova;
    } else {
        Celula *p;
        p = le;
        while (p->prox != NULL) {
            p = p->prox;
        }
        p->prox = nova;
    }
}

void insere_ordenada (int x, Celula *le)
{
    Celula *nova = malloc (sizeof (Celula));
    nova->conteudo = x;
    if (le->prox == NULL) {
        nova->prox = le->prox;
        le->prox = nova;
    } else {
        Celula *an, *at;
        at = le;
        while (at->prox != NULL && at->conteudo > x) {
            an = at;
            at = at->prox;
        }
        if (at == le) {
            nova->prox = le->prox;
            le->prox = nova;
        } else {
            nova->prox = an->prox;
            an->prox = nova;
        }
    }

}


int main ()
{

    Celula *le = criar ();

    insere_ordenada ( 2, le );
    insere_ordenada ( 0, le );
    insere_ordenada ( 5, le );




    printf ("[INICIO]->"); imprime ( le );





    return 0;
}
