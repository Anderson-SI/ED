#include <stdio.h>
#include <stdlib.h>


int main ()
{

    int n;
    scanf("%d", &n);
    int array1[n], array2[n];

    // preenchendo primeiro Array
    for (int j = 0; j < n; j++) {
        scanf("%d", &array1[j]);

    }
    // preenchendo segundo Array
    for (int j = 0; j < n; j++) {
        scanf("%d", &array2[j]);

    }

    // imprimindo os valores dos arrays
    for (int i = 0; i < n; i++) {
        printf("%d\n", array1[i]);
        printf("%d\n", array2[i]);
    }



    return 0;
}
