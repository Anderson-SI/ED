#include <stdio.h>
#include <stdlib.h>

// Função calculaMulta recebe um ponteiro pra inteiro que representa a velocidade
// Imprime qualto será cobrado de multa por exceder a velocidade
void calculaMulta (int *pvel)
{
    if (*pvel > 50)
    {
        float m = (*pvel - 50) / 100.0;
        if (m <= 0.05f)
            printf ("%.2f\n", 230.00);
        else if (m > 0.05f && m <= 0.10f)
            printf ("%.2f\n", 340.00);
        else if (m > 0.10f) {
            printf ("%.2f\n", (*pvel - 50) * 19.28f);
        }
    } else {
        printf ("%.2f\n", 0.0);
    }
}

int main ()
{
    int vel;
    int *pvel; // Ponteiro para vel

    scanf ("%d", &vel);
    pvel = &vel;

    // Chamada a função calculaMulta
    calculaMulta (pvel);

    return 0;
}
