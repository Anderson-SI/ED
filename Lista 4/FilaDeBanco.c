#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição do nó da estrutura fila
typedef struct no {
    int conteudo;
    struct no *prox;
} No;

// função para criar pilha
No* criar_fila (void)
{
    No *cabeca = malloc (sizeof (No));
    cabeca->prox = NULL;
    return cabeca;
}

// função que libera a lista
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

// função para empilhar
void inserir_fila (int x, No *fila)
{
    No *nova = malloc (sizeof (No));
    nova->conteudo = x;
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

void organiza_fila (No *fila1, No *fila2, No *novaFila)
{
    No *auxF1, *auxF2;
    auxF1 = fila1->prox;
    auxF2 = fila2->prox;

    while (auxF1 != NULL && auxF2 != NULL) {
        inserir_fila (auxF1->conteudo, novaFila );
        inserir_fila (auxF2->conteudo, novaFila );
        auxF1 = auxF1->prox;
        auxF2 = auxF2->prox;
    }
    while (auxF1 != NULL) { inserir_fila (auxF1->conteudo, novaFila ); auxF1 = auxF1->prox; }
    while (auxF2 != NULL) { inserir_fila (auxF2->conteudo, novaFila ); auxF2 = auxF2->prox; }
    liberar_fila ( fila1 ); // libera espaço ocupado pela fila 1
    liberar_fila ( fila2 ); // libera espaço ocupado pela fila 2
}

// Pega os valores das filas
void preencher_filas (int *tamF1, int *tamF2, No *filaUm, No *filaDois)
{
    int elemento;
    int k = 0;
    for (int *pk = &k; *pk < *tamF1; (*pk)++) {
        scanf ("%d", &elemento);
        inserir_fila ( elemento, filaUm );
    }

    int j = 0;
    for (int *pj = &j; *pj < *tamF2; (*pj)++) {
        scanf ("%d", &elemento);
        inserir_fila ( elemento, filaDois );
    }
}

// função imprime
void imprimir (No *fila)
{
    No *p;
    for (p = fila->prox; p != NULL; p = p->prox) {
        printf ("%d\n", p->conteudo);
    }
}


int main ()
{
    // Obs: Assim que o programa formar a nova fila liberará a memória alocada pelas
    // duas filas que foram usadas para armazenar os elementos dos caixas;

    int tamF1, tamF2, caixa, elemento;
    scanf ("%d", &tamF1);
    scanf ("%d", &tamF2);
    scanf ("%d", &caixa);

    No *filaUm = criar_fila ();
    No *filaDois = criar_fila ();
    No *NovaFila = criar_fila ();

    preencher_filas ( &tamF1, &tamF2, filaUm, filaDois );

    if (caixa == 1)
        organiza_fila (filaDois, filaUm, NovaFila);
    else if (caixa == 2)
        organiza_fila (filaUm, filaDois, NovaFila);

    imprimir ( NovaFila );




    return 0;
}




