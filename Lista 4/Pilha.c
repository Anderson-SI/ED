#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição do nó da estrutura pilha
typedef struct no {
    int conteudo;
    struct no *prox;
} No;

// função para criar pilha
No* criar_pilha (void)
{
    No *cabeca = malloc (sizeof (No));
    cabeca->prox = NULL;
    return cabeca;
}

// função para empilhar
void empilhar (int *x, No *pilha)
{
    No *nova = malloc (sizeof (No));
    nova->conteudo = *x;
    nova->prox = pilha->prox;
    pilha->prox = nova;
}

// função desempilhar
void desempilhar (No *pilha)
{
    No *lixo;
    if (pilha != NULL) {
        lixo = pilha->prox;
        pilha->prox = lixo->prox;
        free (lixo);
    }
}

// função imprime
void imprimir (No *pilha)
{
    No *p;
    for (p = pilha->prox; p != NULL; p = p->prox) {
        printf ("%d", p->conteudo);
        if (p->prox != NULL) printf (" ");
    }
    printf ("\n");
}

int main ()
{
    No *pilha = criar_pilha ();
    char str[12];
    int n;

    scanf ("%s", &str);
    while (strcmp( str ,"Finalizar") != 0) {
        if (strcmp( str ,"Imprimir") == 0) { imprimir ( pilha ); }
        else {
            scanf ("%d", &n);
            if (strcmp( str ,"Empilhar") == 0) { empilhar ( &n, pilha ); }
            else if (strcmp( str ,"Desempilhar") == 0) { desempilhar ( pilha ); }
        }
    scanf ("%s", &str);
    }





    return 0;
}



