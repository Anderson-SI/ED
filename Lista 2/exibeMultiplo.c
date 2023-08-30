#include <stdio.h>
#include <stdlib.h>

// função multiplo recebe três ponteiros de inteiro
// imprime os múltiplos entre dois deles
void multiplo (int *pi, int *pf, int *px)
{
    int c = 1;
    int *pc = &c;
    while ((*px) * (*pc) <= *pf)
    {
        if ((*px) * (*pc) >= (*pi))
            printf ("%d\n", (*px) * (*pc));
        (*pc)++;
    }
    printf ("\n");
    return;
}


int main ()
{

    int i, f, x;
    scanf ("%d%d%d", &i, &f, &x);

    // chamada a função multiplo
    multiplo (&i, &f, &x);


    return 0;
}
