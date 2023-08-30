#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define M 4

typedef struct reg {
    int leaf; // bool verifica se é folha ou não 1 se sim e 0 se não
    int keyTally; // contagem do número de chaves
    int keys[M-1]; // array de chaves
    struct reg *pointers[M]; // array de filhos
} BtreeNodes; // nó

void inicializa (int m, int *keys, BtreeNodes *poiters[]) {
    for (int i = 0; i < m; i++)
    {
        *(keys + i) = -1;
        *(poiters + i) = NULL;
    }
}

BtreeNodes* criarBtreeNodes ( void )
{
    BtreeNodes* pagina = malloc ( sizeof ( BtreeNodes ));
    pagina->leaf = ;
    pagina->keyTally = ;
    inicializa (M, pagina->keys, pagina->pointers);
}



int main ()
{


    printf("%d \n", sizeof (BtreeNodes));











    return 0;
}
