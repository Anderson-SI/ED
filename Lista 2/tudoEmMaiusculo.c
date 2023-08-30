#include <stdio.h>
#include <stdlib.h>

// função que recebe ponteiro de char para uma string
// converte as minúsculas em maiúculas
void maiuscula (char *s)
{
    while (*s != '\0')
    {
        if (*s >= 97 && *s <= 122)
        {
            *s = *s - 32;
        }
        s++;
    }
}


int main ()
{

    char str[100];
    gets (str);

    // chamada a função para transformar letras minúsculas em maiúsculas
    maiuscula ( str );
    // impressão da string
    printf ("%s\n", str);




    return 0;
}
