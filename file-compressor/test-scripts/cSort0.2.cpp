#include <stdio.h>
#include <stdlib.h>
#define RANGE 255


void countingSort(char a[], char b[], int n) // a = array, b = empty array, n = size
{
    int i;

    int c[RANGE +1];
//    memset(c, 0, sizeof(c));


    for( i = 0; i< n; i++)
    {
        c[a[i]] = c[a[i]] + 1;
    }
    for(i = 1; i<RANGE; i++)
    {
        c[i] = c[i] + c[i-1];
    }
    for(i = n-1; i>=0; i--)
    {
        b[c[a[i]] - 1] = a[i];
        c[a[i]] = c[a[i]] - 1;
    }

}

int main()
{
    char a[10] = {'c','b','c','d','E','C','a','A','b','C'};
    int n = 10;
    char b[10];
    int i;
    for( i = 0; i<n;i++)
    {
        printf("%c",a[i]);
    }
    printf("\n");
    countingSort(a,b,n);
    for( i = 0; i<n;i++)
    {
        printf("%c",b[i]);
    }
    printf("\n");

    return 0;
}