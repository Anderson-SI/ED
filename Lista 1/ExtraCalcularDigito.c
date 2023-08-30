#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função digMaior recebe um ponteiro para array de char
// e um inteiro indicando a posição de início no array
// Devolve o maior número entre 3
int digMaior (char *s, int ini)
{
    int maior = s[ini];
    for (int j = ini + 1; j < ini + 3; j++)
    {
        if (s[j] > maior)
        {
            maior = s[j];
        }
    }
    return maior;
}

// Função digitoVerificador recebe um ponteiro para array de char
// devolve 1 caso o último dígito do array seja igual ao dígito verificador
// 0 se não for igual.
int digitoVerificador (char *ps)
{
    int digUltimo = ps[12] - 48;
    int d1 = digMaior (ps, 0) - 48;
    int d2 = digMaior (ps, 4) - 48;
    int d3 = digMaior (ps, 8) - 48;
    int digito = (d1 + d2 + d3) % 10;
    if (digito == digUltimo)
        return 1;
    else
        return 0;
}

int main ()
{
    char s[13];
    char *ps;

    scanf ("%s", &s);
    while (strcmp(s, "FIM") != 0)
    {
        ps = s;
        if (digitoVerificador (ps)) {
            printf ("VALIDO\n");
        } else {
            printf ("INVALIDO\n");
        }
        scanf ("%s", &s);
    }
    printf ("\n");

    return 0;
}
