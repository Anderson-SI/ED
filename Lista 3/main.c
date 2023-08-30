#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void insertion_ (int tam, int array[])
{
    for (int i = 1; i < tam; i++){
        int k = i - 1;
        int j = i;
        while (k >= 0) {
            if (array[j] < array[k]) {
                int aux = array[j];
                array[j] = array[k];
                array[k] = aux;
                k--;
                j--;
            } else {
                break;
            }
        }
    }
}

int main ()
{

    int v[10] = {6,3,7,2,1,9,10,8,11,20};

    insertion_ (10, v);



    for (int j = 0; j < 10; j++) {
        printf ("%d ", v[j]);
    }




    return 0;
}

