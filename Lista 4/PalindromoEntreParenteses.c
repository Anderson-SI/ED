#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// na criação das estruturas chamei no para representar um nó da pilha
// e celula para representar um nó da fila
// preferir definir uma estrutura para pilha e outra para celula logo que estou usando estruturas diferentes
// e além disso tenho um contador no topo da minha pilha que me ajuda a identificar desempilhamento além do normal
typedef struct no {
    char conteudo;
    int cont;
    struct no *prox;
} No;

typedef struct celula {
    char conteudo;
    struct celula *prox;
} Celula;

// criar lista
No *criar_pilha (void)
{
    No *cabeca = malloc (sizeof (No));
    cabeca->prox = NULL;
    cabeca->cont = 0;
    return cabeca;
}

// criar lista
Celula *criar_fila (void)
{
    Celula *cabeca = malloc (sizeof (Celula));
    cabeca->prox = NULL;
    return cabeca;
}

// função para inserir na fila na ordem em que as palavras é escrita da esquerda para direita
void inserir_fila (char c, Celula *fila)
{
    Celula *nova = malloc (sizeof (Celula));
    nova->conteudo = c;
    nova->prox = NULL;
    if (fila == NULL) { fila->prox = nova; }
    else {
        Celula *aux;
        aux = fila;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = nova;
    }
}

void inserir (char c, Celula *fila)
{
    Celula *novo = malloc (sizeof (Celula));
    novo->conteudo = c;
    novo->prox = fila->prox;
    fila->prox = novo;
}


int inverte_fila_compara (Celula *filaOriginal, Celula *filaInvertida)
{
    Celula *aux, *pfilaOriginal, *pfilaInvertida;
    for (aux = filaOriginal->prox; aux != NULL; aux = aux->prox) {
        inserir ( aux->conteudo , filaInvertida);
    }
    pfilaInvertida = filaInvertida->prox;
    pfilaOriginal = filaOriginal->prox;
    while (pfilaOriginal != NULL) {
        if ( pfilaOriginal->conteudo != pfilaInvertida->conteudo ) {
            return 0;
        }
        pfilaInvertida = pfilaInvertida->prox;
        pfilaOriginal = pfilaOriginal->prox;
    }
    return 1;
}

// função para empilhar
void empilhar (char *c, No *pilha)
{
    No *novo = malloc (sizeof (No));
    novo->conteudo = *c;
    novo->prox = pilha->prox;
    pilha->prox = novo;
}

// função para desempilhar
void desempilhar (No *pilha)
{
    No *lixo;
    if (pilha->prox != NULL) {
        lixo = pilha->prox;
        pilha->prox = lixo->prox;
        free(lixo);
    } else {
      pilha->cont = pilha->cont - 1;
    }
}

// função para liberar fila
void liberar_fila (Celula *fila)
{
    if (fila != NULL) {
        Celula *lixo;
        while (fila != NULL) {
            lixo = fila;
            fila = fila->prox;
            free (lixo);
        }
        free (fila);
    }
}

void imprimir (No *pilha, Celula *filaOriginal, Celula *filaInvertida)
{
        char sPb[16];
        char sPal[4];
        if (pilha->prox == NULL && pilha->cont == 0)
            strcpy (sPb,"BALANCEADOS");
        else
            strcpy (sPb,"NAO BALANCEADOS");
        if ( inverte_fila_compara ( filaOriginal, filaInvertida ))
            strcpy (sPal, "SIM");
        else
            strcpy (sPal, "NAO");
        liberar_fila(filaOriginal);
        liberar_fila(filaInvertida);
        printf ("---\n");
        printf ("PARENTESES: %s\n", sPb);
        printf ("PALINDROMO: %s\n", sPal);
        printf ("---\n");
}

int main ()
{

    No *pilha = criar_pilha (); // criação da pilha
    Celula *filaOriginal = criar_fila (); // criação da fila
    Celula *filaInvertida = criar_fila (); // criação da fila para inverter

    char c;
    scanf ("%c", &c);
    while (c != '\n' && c != NULL) {
        if (c == '(')
            empilhar ( &c , pilha );
        else if (c == ')')
            desempilhar ( pilha );
        else {
            inserir (c, filaInvertida );
            inserir_fila (c , filaOriginal );
        }


    scanf ("%c", &c);
    if (c == '\n') {
        imprimir ( pilha, filaOriginal, filaInvertida );
        filaOriginal = criar_fila ();
        filaInvertida = criar_fila ();
        scanf ("%c", &c);
        }
    }


    return 0;
}

