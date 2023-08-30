#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct no {
    int tEspera;
    int tAtendimento;
    int tChegada;
    struct no *prox;
} No;

No *criar_fila ( void )
{
    No *novo = malloc ( sizeof ( No ));
    novo->prox = NULL;
    return novo;
}

int calculaTempo ( No *fila )
{
    int tempo = 0;
    if (fila->prox == NULL) { return tempo; }
    else {
        No *aux = fila;
        while (aux->prox != NULL) { aux = aux->prox; tempo = tempo + aux->tAtendimento; }
    }
    return tempo;
}


void inserir_fila (int caixa, int tChegada, int tAtendimento, No *fila)
{
    No *novo = malloc (sizeof ( No ));

    novo->tChegada = tChegada;
    novo->tAtendimento = tAtendimento;

    if (fila->prox == NULL)
    {
        novo->tEspera = 0;
        novo->prox = fila->prox;
        fila->prox = novo;

    } else {

        int tempo = calculaTempo ( fila );

        No *aux = fila;
        while (aux->prox != NULL) { aux = aux->prox; }

        novo->tEspera = (tempo - tChegada) / caixa;
        novo->prox = aux->prox;
        aux->prox = novo;

    }
}

void imprimir_fila ( No *fila )
{
    No *p;
    for (p = fila->prox; p != NULL; p = p->prox)
    {
        printf ("tEspera: %d - tAtendimento: %d - tChegada: %d \n", p->tEspera, p->tAtendimento, p->tChegada);
    }
}

int contaPessoas ( No *fila )
{
    No *p;
    int qtd = 0;

    for (p = fila->prox; p != NULL; p = p->prox) {
        if (p->tEspera > 20)
            qtd++;
    }
    return qtd;
}


int main ()
{
    // 1 <= C <= 10        n caixas
    // 1 <= N <= 1000      n clientes
    // 0 <= T <= 300       horario que entrou
    // 1 <= D <= 10        tempo necessário para atender o cliente

    int c; // nº caixas
    int n; // nº clientes
    int t; // horário que entrou na fila
    int d; // tempo necessário para atender o cliente
    char a; // artifícil para ajudar na leitura dos dados

    No *fila = criar_fila ();

    scanf ("%d%c%d", &c, &a, &n);
    int k = 0;
    for (int *pk = &k; *pk < n; (*pk)++)
    {
        scanf ("%d%c%d", &t, &a, &d);
        inserir_fila ( c, t, d, fila );
    }

    imprimir_fila ( fila );

    printf ("qtd: %d\n", contaPessoas ( fila ));

    return 0;
}







