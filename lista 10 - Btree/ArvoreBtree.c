#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define M 4

typedef struct reg {
    int leaf; // bool verifica se � folha ou n�o 1 se sim e 0 se n�o
    int keyTally; // contagem do n�mero de chaves
    int keys[M-1]; // array de chaves
    struct reg *pointers[M]; // array de filhos
} BtreeNodes; // n�

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
