#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct no {
    int chave;
    struct no *prox;
} No;

No *criar ( void )
{
    No *n = malloc ( sizeof ( No ));
    n->prox = NULL;
    return n;
}

// função inserir, insere os elementos em de forma ordenada
void inserir (No *tb, int ch) // insere de forma ordenada
{
    No *n = malloc (sizeof ( No ));
    n->chave = ch;
    if (tb->prox == NULL) {
        n->prox = tb->prox;
        tb->prox = n;
    } else {
        No *p = tb;
        while (p->prox != NULL)
        {
            p = p->prox;
        }
        n->prox = p->prox;
        p->prox = n;
    }
}

// função hash dada uma chave devolve o resto da divisão da chave pelo tamanho da tabela
int hash (int ch, int *m)
{
    return ch % *m;
}

// função imprimi
void imprimir ( No *tb )
{
    char b = '\\';
    No *p = tb->prox;
    if (p == NULL) { printf ("%c", b); }
    else {
        while (p != NULL)
        {
            printf ("%d -> ", p->chave);
        p = p->prox;
        }
    printf ("%c", b);
    }
    printf ("\n");
}

void liberar ( No *lista )
{
    if (lista != NULL) {
        No *lixo;
        while (lista != NULL) {
            lixo = lista;
            lista = lista->prox;
            free (lixo);
        }
    }
}

void liberarMenoria ( No **tb, int *m )
{
    for (int h = 0; h < *m; h++) {
        No *p = *(tb + h);
        liberar ( p );
    }
    free ( tb );

}


int main ()
{

    int qtdTeste;
    scanf ("%d", &qtdTeste);

    while (qtdTeste > 0) {

        int m, elem, ch;
        char g, c;

        scanf ("%d%c%d", &m, &g, &elem);
        No **tabela = malloc (m * sizeof ( No ));
        for (int j = 0; j < m; j++) {
            *(tabela + j) = criar ();
        }

        while (elem > 0) {
            scanf ("%d%c", &ch, &c);
            int h = hash ( ch, &m );
            No *pLis = *(tabela + h);
            inserir ( pLis, ch);
        elem--;
        }

        // imprimir
        for (int k = 0; k < m; k++) {
            No *p = *(tabela + k);
            printf ("%d -> ", k);
            imprimir ( p );
        }

        // libero a memória alocada pelo array de ponteiros
        // Por que vou ter que fazer vários casos de teste, então, não preciso manter o array alocado
        liberarMenoria ( tabela, &m );



    printf ("\n");
    qtdTeste--;
    }

    return 0;
}


