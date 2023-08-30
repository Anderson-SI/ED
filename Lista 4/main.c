#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char conteudo;
    struct no *prox;
} No;

No *criar_pilha (void)
{
    No *cabeca = malloc (sizeof (No));
    cabeca->prox = NULL;
    return cabeca;
}

void empilhar (char c, No *pilha)
{
    No *novo = malloc (sizeof (No));
    novo->conteudo = c;
    novo->prox = pilha->prox;
    pilha->prox = novo;
}

void desempilhar (No *pilha)
{
    No *lixo;
    if (pilha != NULL)
        lixo = pilha->prox;;
        pilha->prox = lixo->prox;
        free(lixo);
}

void imprimir (No *pilha)
{
    No *p;
    for (p = pilha->prox; p != NULL; p = p->prox) {
        printf ("%c ", p->conteudo);
    }
    printf ("\n");
}

int main ()
{
    No *pesquerda = criar_pilha ();
    No *pdireita = criar_pilha ();
    int j = 0;

    char c;
    scanf ("%c", &c);

    while ( c != '\n') {
        if (c == '(')
            empilhar ( c , pesquerda );
        else if (c == ')')
            empilhar ( c , pdireita );
    scanf ("%c", &c);
    }

    imprimir ( pesquerda );
    imprimir ( pdireita );






    return 0;
}

/*
    ----
    PARENTESES: BALANCEADOS
    PARENTESES: NAO BALANCEADOS
    PALINDROMO: SIM
    PALINDROMO: NAO
----
*/

