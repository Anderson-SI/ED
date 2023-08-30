#include <stdio.h>
#include <stdlib.h>

void insertionSort (int n, int v[])
{
    for (int j = 1; j < n; j++)
    {
        int x = v[j];
        int i = j - 1;
        while (i >= 0 && v[i] > x)
        {
            v[i + 1] = v[i];
            i = i - 1;
        }
        v[i+1] = x;
    }
}




int main ()
{

    int v[] = {5, 4, 3, 2, 1};

    insertionSort (5, v);

    for (int i = 0; i < 5; i++)
        printf ("%d\n", v[i]);




    return 0;
}
