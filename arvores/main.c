#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main ()
{

    int n, *pn = &n;
    int k, *pk = &k;
    int r, *pr = &r;

    int S, *pS = &S;
    int L, *pL = &L;
    int R, *pR = &R;

    char c, *pc = &c;


    scanf ("%d %c %d", pn, pc, pr);
    printf ("%d %c %d\n", *pn, *pc, *pr);



    return 0;
}

