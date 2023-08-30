#include <stdio.h>
#include <stdlib.h>

// Definição do nó da estrutura lista
typedef struct no {
    int conteudo;
    struct no *prox;
} No;

// função para criar lista
No* criar_lista (void)
{
    No *cabeca = malloc (sizeof (No));
    cabeca->prox = NULL;
    return cabeca;
}

// função que insere elementos na lista
void inserir (int x, No *lista)
{
    No *novo = malloc (sizeof (No));
    novo->conteudo = x;
    novo->prox = lista->prox;
    lista->prox = novo;
}
// função que localiza elemento dentro de uma lista
int busca_elemento (int *x, No *lis)
{
    No *p;
    for (p = lis->prox; p != NULL; p = p->prox) {
        if (p->conteudo == (*x)) { return 1; }
    }
    return 0;
}

// função que verifica se uma lista é sub conjunto de outra
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

// função que preenche a lista com os dados inseridos pelo usuário
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

    // Verifica qual conjunto é maior
    // if (tb < ta) {
    printf ("%d\n", sub_conjunto (liA, liB));
    //} else { printf ("%d\n", sub_conjunto (liB, liA)); }




    return 0;
}


