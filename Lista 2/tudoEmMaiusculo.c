#include <stdio.h>
#include <stdlib.h>

// fun��o que recebe ponteiro de char para uma string
// converte as min�sculas em mai�culas
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

    // chamada a fun��o para transformar letras min�sculas em mai�sculas
    maiuscula ( str );
    // impress�o da string
    printf ("%s\n", str);




    return 0;
}
