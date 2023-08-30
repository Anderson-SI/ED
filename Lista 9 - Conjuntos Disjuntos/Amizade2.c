#include  <stdio.h>
#include <stdlib.h>

void preenchimento ( int pares, int array [], int índices []);
void  inicia ( int novosIndices [], int pares);
int  percorre ( int i, int array []);
int  conta ( int pares, int array []);
void  une ( int pares, int array [], int novosIndices [], int índices []);

int  main () {
    testículos int , pessoas, pares;
    scanf ( " % d " , & testes);
    int i = 0 ;
    enquanto (i <testes) {
        scanf ( " % d  % d " , & pessoas, & pares);
        int array [pares * 2 ], índices [pares * 2 ], novosIndices [pares * 2 ];
        if (pares == 1 ) {
            preencher (pares, matriz, índices);
            printf ( " 2 \ n " );
        }
        else {
            preencher (pares, matriz, índices);
            inicia (novosIndices, pares);
            une (pares, array, novosIndices, índices);
        }
        i ++;
    }
    return  0 ;
}

void  fill ( int pares, int array [], int indices []) {
    int i, a = 1 ;
    para (i = 0 ; i <pares * 2 ; i ++) {
        scanf ( " % d " , & array [i]);
        índices [i] = a;
        if ((i + 1 )% 2 == 0 )
            a ++;
    }
}

void  inicia ( int novosIndices [], int pares) {
    int i;
    para (i = 0 ; i <pares * 2 ; i ++)
        novosIndices [i] = - 1 ;
}

int  percorre ( int i, int array []) {
    int j;
    para (j = 0 ; array [j]! = - 1 ; j ++) {
        if (array [j] == i)
            return  1 ;
    }
    return  0 ;
}

int  conta ( int pares, int array []) {
    int i, num = 0 ;
    para (i = 0 ; i <pares * 2 ; i ++) {
        if (array [i]! = - 1 )
            num ++;
    }
    return num;
}

void  une ( int pares, int array [], int novosIndices [], int indices []) {
    int i = 0 , j, a = 2 , c = 0 , maior = 0 ;
    enquanto (c <pares * 2 ) {
        if (matriz [c]! = 0 ) {
            i = 0 ;
            a = 2 ;
            novosIndices [ 0 ] = matriz [c];
            novosIndices [ 1 ] = matriz [c + 1 ];
            enquanto (novosIndices [i]! = - 1 ) {
                para (j = 0 ; j <pares * 2 ; j ++) {
                    if (array [j] == novosIndices [i]) {
                        matriz [j] = 0 ;
                        int aux = indices [j] == indices [j + 1 ]? j + 1 : j- 1 ;
                        if ( percorre (array [aux], novosIndices)! = 1 ) {
                            novosIndices [a] = array [aux];
                            a ++;
                        }
                        matriz [aux] = 0 ;
                    }
                }
                i ++;
            }
        }
        int   p = conta (pares, novosIndices);
        if (p> maior)
            maior = p;
        inicia (novosIndices, pares);
        c ++;
    }
        printf ( " % d \ n " , maior);
}
