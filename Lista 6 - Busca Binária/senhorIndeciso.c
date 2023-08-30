#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int main ()
{
    int n, qtdReq, req;

    scanf ("%d", &n);
    int *vValores = malloc (n * sizeof ( int ));

    for (int i = 0; i < n; i++) {
        scanf ("%d", (vValores + i));
    }

    scanf ("%d", &qtdReq); // lendo as requisiões
    for (int h = 0; h < req; h++) {
        scanf ("%d", &req);

    }




    return 0;
}
