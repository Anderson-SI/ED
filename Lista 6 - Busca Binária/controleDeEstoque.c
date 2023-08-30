#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// aloca uma matriz para guardar código e produto
int **listaDeProduto ()
{
    int **M = (int**) malloc ( 100 * sizeof ( int* ));
    for (int k = 0; k < 100; k++) {
        *(M + k) = (int*) malloc ( 2 * sizeof (int));
    }
    return M;
}

void buscaBinaria (int ini, int tam, int **mListaProduto, int codPro, int qtdMer, int *flag)
{
    int t = tam-1;
    int meio;

    if (ini <= t)
    {
        meio = (ini + t) / 2;
        if (mListaProduto[meio][0] == codPro) {
            if (mListaProduto[meio][1] >= qtdMer) {
                mListaProduto[meio][1] = mListaProduto[meio][1] - qtdMer;
                *flag = 1;
            }
        }
        buscaBinaria (ini, meio, mListaProduto, codPro, qtdMer, flag); // esquerdo
        buscaBinaria (meio + 1, tam, mListaProduto, codPro, qtdMer, flag); // direito
    }
    return;
}




int main ()
{

    int t = 0;
    int *pt = &t;
    int **mListaProduto = listaDeProduto ( ); // aloca uma matriz para guardar produto e quantidade

    int cod, qtd;

    int j = 0;
    scanf ("%d", &cod);
    while (cod != 9999 && j < 100) { // faz a leitura dos produtos e quantidades
        scanf ("%d", &qtd);
        mListaProduto[j][0] = cod;
        mListaProduto[j][1] = qtd;
        *pt = *pt+1;
    scanf ("%d", &cod);
    j++;
    }


    int tam = *pt;
    int cliente, codPro, qtdMer;
    do {                            // recebe o cliente, produto e quantidade
        scanf ("%d", &cliente);
        if (cliente != 9999) {
            scanf ("%d%d", &codPro, &qtdMer);
            int flag = 0;
            buscaBinaria (0, tam, mListaProduto, codPro, qtdMer, &flag);  // verifico se há estoque ou não
            if (flag == 1) { printf ("OK\n"); }
            else { printf ("ESTOQUE INSUFICIENTE\n"); }
        }
    } while (cliente != 9999);


    // imprimindo o que ficou restou das quantidades do produto
    for (int j = 0; j < *pt; j++)
    {
        printf ("%d %d", mListaProduto[j][0], mListaProduto[j][1]);
        printf ("\n");
    }








    return 0;
}
