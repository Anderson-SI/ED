#include <stdio.h>
#include <stdlib.h>

void imprimir (int t, int *v, int elemento)
{
    for (int k = t - 1; k >= 0; k--)
        printf ("%d %d\n", elemento, *(v + k));
}

void buscaBinaria (int ini, int tam, int *vIndice, int *vCodigo, int *vTelefone, int *vOcorrencia, int elemento, int *nOcor)
{
    int t = tam-1;
    int meio;

    if (ini <= t)
    {
        meio = (ini + t) / 2;
        if (*(vCodigo + meio) == elemento) {
            *(vOcorrencia + *nOcor) = *(vTelefone + meio);
            *nOcor = *nOcor + 1;
        }
        buscaBinaria (ini, meio, vIndice, vCodigo, vTelefone, vOcorrencia, elemento, nOcor); // esquerdo
        buscaBinaria (meio + 1, tam, vIndice, vCodigo, vTelefone, vOcorrencia, elemento, nOcor); // direito
    }
    return;
}



int main ()
{
    int *vCodigo = malloc (15 * sizeof ( int ));
    int *vTelefone = malloc (15 * sizeof ( int ));
    int *vOcorrencia = malloc (15 * sizeof ( int ));

    int *vIndice = malloc (15 * sizeof ( int ));
    for (int k = 0; k < 15; k++) { *(vIndice + k) = k; }

    int i = 0; char c;
    while (i < 15)
    {
        printf ("Digite o codigo de area e o telefone:\n");
        scanf ("%d%c%d", (vCodigo + i), &c, (vTelefone + i));
        i++;
    }

    printf ("Digite o codigo de area desejado:\n");
    int elemento;
    scanf ("%d", &elemento);

    int oc = 0;
    int *nOcor = &oc;
    buscaBinaria ( 0 , 15, vIndice, vCodigo, vTelefone, vOcorrencia, elemento, nOcor);

    if (*nOcor != 0) {
        printf("Telefones com o codigo de area %d:\n", elemento);
        imprimir ( *nOcor , vOcorrencia, elemento);
    } else {
        printf ("Nao ha nenhum telefone com o codigo %d\n", elemento);
    }


    return 0;
}
