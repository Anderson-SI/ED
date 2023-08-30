#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char conteudo;
    int cont;
    struct no *prox;
} No;

// criar lista
No *criar_ (void)
{
    No *cabeca = malloc (sizeof (No));
    cabeca->prox = NULL;
    cabeca->cont = 0;
    return cabeca;
}

// função para inserir na fila na ordem em que as palavras é escrita da esquerda para direita
void inserir_fila (char c, No *fila)
{
    No *nova = malloc (sizeof (No));
    nova->conteudo = c;
    nova->prox = NULL;
    if (fila == NULL) { fila->prox = nova; }
    else {
        No *aux;
        aux = fila;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = nova;
    }
}

void inserir (char c, No *fila)
{
    No *novo = malloc (sizeof (No));
    novo->conteudo = c;
    novo->prox = fila->prox;
    fila->prox = novo;
}


int inverte_compara (No *filaOriginal, No *filaInvertida)
{
    No *pfO, *pfI;
    pfI = filaInvertida->prox;
    for ( pfO = filaOriginal->prox; pfO != NULL; pfO = pfO->prox) {
        if ( pfO->conteudo != pfI->conteudo ) {
            return 0;
        }
        pfI = pfI->prox;
    }
    return 1;
}

// função para empilhar
void empilhar (char c, No *pilha)
{
    No *novo = malloc (sizeof (No));
    novo->conteudo = c;
    novo->prox = pilha->prox;
    pilha->prox = novo;
}

// função para desempilhar
void desempilhar (No *pilha)
{
    No *lixo;
    if (pilha->prox != NULL) {
        lixo = pilha->prox;;
        pilha->prox = lixo->prox;
        free(lixo);
    } else {
      pilha->cont = pilha->cont - 1;
    }
}

// função para liberar fila
void liberar_fila (No *fila)
{
    if (fila != NULL) {
        No *lixo;
        while (fila != NULL) {
            lixo = fila;
            fila = fila->prox;
            free (lixo);
        }
        free (fila);
    }
}

void gerar_ (char *str, No *pilha, No *filaOriginal, No *filaInvertida)
{
    int j = 0;
    while (*(str+j) != '\0') {
        if (*(str+j) == '(')
            empilhar ( *(str+j) , pilha );
        else if (*(str+j) == ')')
            desempilhar ( pilha );
        else {
            inserir ( *(str+j) , filaInvertida );
            inserir_fila ( *(str+j) , filaOriginal );
        }
    j++;
    }
}

char *criar_string (void)
{
    char *str = malloc (1000 * sizeof (char));
    return str;
}

void liberar_memoria (char *str, No *filaInvertida, No *filaOriginal)
{
    liberar_fila(filaOriginal);
    liberar_fila(filaInvertida);
    if (str != NULL)
        free (str);
}

int main ()
{
    char *pal;
    char *par;

    No *pilha;
    No *filaOriginal;
    No *filaInvertida;

    char *str;
    str = criar_string ();
    printf ("\n");
    while (gets (str) != NULL ){
        pilha = criar_ ();
        filaOriginal = criar_ ();
        filaInvertida = criar_ ();

        gerar_ ( str , pilha, filaOriginal, filaInvertida);

        if (pilha->prox == NULL && pilha->cont == 0)
            par = "BALANCEADOS";
        else
            par = "NAO BALANCEADOS";
        if ( inverte_compara ( filaOriginal, filaInvertida ) && filaOriginal->prox != NULL)
            pal = "SIM";
        else
            pal = "NAO";

        printf ("---\n");
        printf ("PARENTESES: %s\n", par);
        printf ("PALINDROMO: %s\n", pal);

        liberar_memoria (str, filaInvertida, filaOriginal);
        str = criar_string ();

    }
    printf("---\n");


    return 0;
}

