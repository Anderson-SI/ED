#include <stdio.h>
#include <stdlib.h>

// definição da minha estrutura ponto
typedef struct no {
    int id;
    int idade;
    struct no *prox;
} No;

// função que cria fila
No* criar_fila (void)
{
    No *cab = malloc (sizeof (No));
    cab->prox = NULL;
    return cab;
}

// função insere na fila
void inserir_fila (int *id, int *idade, No *fila)
{
    No *novo = malloc (sizeof (No));
    novo->id = *id;
    novo->idade = *idade;
    novo->prox = NULL;
    if (fila == NULL) {
        fila->prox = novo;
    }
    else {
        No *aux;
        aux = fila;
        while (aux->prox != NULL) { aux = aux->prox; }
        aux->prox = novo;
    }
}

// função para imprimir
void imprimir ( No *fila )
{
    No *p;
    for (p = fila->prox; p != NULL; p = p->prox) {
        printf ("ID: %d IDADE: %d\n", p->id, p->idade);
    }
}

// função para remover
void remove_ ( No *fila )
{
    No *lixo;
    if (fila->prox != NULL) {
        lixo = fila->prox;
        fila->prox = lixo->prox;
        free(lixo);
    }
}


int main ()
{
    int n, n1, *pn, *pn1;
    pn = &n;
    pn1 = &n1;

    scanf ("%d", &n);
    *pn1 = *pn;
    No *idosos = criar_fila ();
    No *naoIdosos = criar_fila ();

    char c;
    scanf ("%c", &c);
    while (c != 'f') {
        int Id, Idade;
        switch (c)
        {
            case 'a' :
                scanf ("%d", &Id);
                scanf ("%d", &Idade);
                if (Idade > 60) { inserir_fila ( &Id, &Idade, idosos ); }
                else { inserir_fila ( &Id, &Idade, naoIdosos ); }
                break;
            case 'r' :
                if (*pn > 0) {
                    if (idosos->prox != NULL) { remove_ ( idosos ); (*pn) = (*pn) - 1; }
                    else { remove_ ( naoIdosos ); }
                } else {
                    remove_ ( naoIdosos );
                    *pn = *pn1;
                }
                break;
            case 'i' :
                printf ("fila de idosos:\n");
                if (idosos->prox == NULL) { printf ("fila vazia!\n"); }
                else { imprimir ( idosos ); }
                printf ("fila de nao-idosos:\n");
                if (naoIdosos->prox == NULL) { printf ("fila vazia!\n"); }
                else { imprimir ( naoIdosos ); }
                printf ("----------\n");
                break;
        }
    scanf ("%c", &c);
    }


    return 0;
}
