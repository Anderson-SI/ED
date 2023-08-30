#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Estrutura ponto
struct ponto {
    float x;
    float y;
};

// Fun��o dist recebe dois ponteiros para estura do tipo ponto
// devolve a dist�ncia entre os dois pontos
float dist (struct ponto *p1, struct ponto *p2)
{
    return sqrt((p2->x - p1->x) * (p2->x - p1->x) + (p2->y - p1->y) * (p2->y - p1->y));
}

// Fun��o posPlanoCartesiano recebe um ponto
// imprime a posi��o do ponto no plano cartesiano
void posPlanoCartesiano (struct ponto p) {
        if (p.x == 0 && p.y == 0) {
            printf("Origem\n");
        }
        if (p.x == 0 && p.y > 0) {
            printf("eixo y positivo\n");
        }
        if (p.x == 0 && p.y < 0) {
            printf("eixo y negativo\n");
        }
        if (p.x < 0 && p.y == 0) {
            printf("eixo x negativo\n");
        }
        if (p.x > 0 && p.y == 0) {
            printf("eixo x positivo\n");
        }
        if (p.x > 0 && p.y > 0) {
            printf("quadrante 1\n");
        }
        if (p.x < 0 && p.y > 0) {
            printf("quadrante 2\n");
        }
        if (p.x < 0 && p.y < 0) {
            printf("quadrante 3\n");
        }
        if (p.x > 0 && p.y < 0) {
            printf("quadrante 4\n");
        }
        return;
}

int main()
{
    typedef struct ponto Ponto;
    Ponto p1, p2;

    int n;
    float maiorDist = 0;
    scanf("%d", &n);

    // arrays para armazenar os pontos
    Ponto array1[n];
    Ponto array2[n];

    // l� os dados dos pontos digitados pelos usu�rio
    for (int j = 0; j < n; j++)
    {
        scanf("%f%f%f%f", &p1.x, &p1.y, &p2.x, &p2.y);
        float d = dist (&p1, &p2);
        if (maiorDist < d)
        {
            maiorDist = d;
        }
        array1[j] = p1;
        array2[j] = p2;
    }

    // imprime a maior dist�ncia
    printf("%.2f\n", maiorDist);

    // imprime a posi��o dos pontos no plano
    for (int i = 0; i < n; i++)
    {
        posPlanoCartesiano (array1[i]);
        posPlanoCartesiano (array2[i]);
    };

    return 0;
}
