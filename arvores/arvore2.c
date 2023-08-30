#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// estrutura da árvore
typedef struct no {
    int chave;
    int conteudo; // armazena os dados
    struct no *dir, *esq;
} noh; // nó


// definição do tipo árvore
typedef noh *arvore; // arvore

int n = 0;
int *vn;


// altura da árvore
// essa definição é diferente da que o professor deu, ou seja, soma 1
int altura(arvore r)
{
    if (r == NULL) {
        return -1; // altura da árvore vazia
    }
    else {
        int he = altura (r->esq);
        int hd = altura (r->dir);
        if (he < hd) return hd + 1;
        else return he + 1;
    }

}

// varredura da árvore e-r-d
void red(arvore r)
{
    if (r != NULL) {
        red ( r->esq );
        printf ("%d", r->conteudo);
        red ( r->dir );
    }
}


// colocando os elementos dentro do vetor em ordem
// varredura da árvore e-r-d
void red(arvore r)
{
    if (r != NULL) {
        red ( r->esq );
        vn[n++] = r->conteudo;
        red ( r->dir );
    }
}



// função aloca um nó
// devolve o endereço do nó
noh novono ( int k )
{
    noh *novo = malloc (sizeof ( noh ));
    novo->dado = k;
    novo->esq = novo->dir = NULL;
    return novo;
}

// remoção de um nó
arvore removeraiz (arvore r) {
    noh *p, *q;
    if (r->esq == NULL) {
       q = r->dir;
       free (r);
       return q;
    }
    p = r; q = r->esq;
    while (q->dir != NULL) {
       p = q; q = q->dir;
    }
    // q é nó anterior a r na ordem e-r-d
    // p é pai de q
    if (p != r) {
       p->dir = q->esq;
       q->esq = r->esq;
    }
    q->dir = r->dir;
    free (r);
    return q;
}

void ABB (){
    int abb = 1;
    for (int i = 1; i < n; i++)
    {
        if (vn[i - 1] > vn[i]) {
            abb = 0; break;
        }
    }
    if (abb) printf ("VERDADEIRO");
    else printf ("FALSO");

}


arvore inser_red (arvore r)
{
    int out, *pout = &out;
    int num, *pnum = &num;
    char str[2], *pstr = &str[0];

    scanf ("%c", pstr);
    if (*pstr == ' ') scanf ("%c", pstr);

    if (*pstr == '(') // é '('
    {
        if (scanf("%d", pnum))
        {
            r = novono (*pnum); n++;
        }
        else {
            scanf("%c", pstr); // não é numero
            return r;
        }
        r->esq = insere_red ( r->esq );
        r->dir = inser_red ( r->dir );
        scanf ("%c", pstr);
    }
    return r;
}

int main ()
{

    arvore r = NULL;
    r = insere_red ( r );
    vn = malloc ( n * sizeof ( int ));
    n = 0;
    erd ( r );
    ABB ( );

    return 0;
}
