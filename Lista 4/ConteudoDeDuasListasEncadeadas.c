#include <stdio.h>
#include <stdlib.h>

// Defini��o do n� da estrutura lista
typedef struct no {
    int conteudo;
    struct no *prox;
} No;

// fun��o para criar lista
No* criar_lista (void)
{
    No *cabeca = malloc (sizeof (No));
    cabeca->prox = NULL;
    return cabeca;
}

// fun��o que insere elementos na lista
void inserir (int x, No *lista)
{
    No *novo = malloc (sizeof (No));
    novo->conteudo = x;
    novo->prox = lista->prox;
    lista->prox = novo;
}
// fun��o que localiza elemento dentro de uma lista
int busca_elemento (int *x, No *lis)
{
    No *p;
    for (p = lis->prox; p != NULL; p = p->prox) {
        if (p->conteudo == (*x)) { return 1; }
    }
    return 0;
}

// fun��o que verifica se uma lista � sub conjunto de outra
int sub_conjunto (No *listaA, No *listaB)
{
    No *pA, *pB;
    pB = listaB;

    if (pB->prox == NULL) { return 1; }
    else {
        for (pB = listaB->prox; pB != NULL; pB = pB->prox) {
                if ( !(busca_elemento ( &pB->conteudo, listaA))) { return 0; }
            }
    }
    return 1;
}

// fun��o que preenche a lista com os dados inseridos pelo usu�rio
void preencher_lista (int *ta, No *lista)
{
    int conteudo;
    int k = 0;
    for (int *pk = &k; *pk < *ta; (*pk)++) {
        scanf ("%d", &conteudo);
        inserir (conteudo, lista);
    }
}

int main ()
{
    int ta, tb;
    No *liA = criar_lista ();
    No *liB = criar_lista ();

    scanf ("%d", &ta);
    preencher_lista ( &ta, liA);

    scanf ("%d", &tb);
    preencher_lista ( &tb, liB);

    // Verifica qual conjunto � maior
    // if (tb < ta) {
    printf ("%d\n", sub_conjunto (liA, liB));
    //} else { printf ("%d\n", sub_conjunto (liB, liA)); }




    return 0;
}


