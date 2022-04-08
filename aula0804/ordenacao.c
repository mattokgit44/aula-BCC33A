#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ordenacao.h"

int max(int *v, int n){

    int maior = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] > v[maior])
        {
            maior = v[i];
        }
    }
    
    return maior;
}

void counting_sort(int *v, int n, int div, int base, int *s){
    
    int i, t, c[base], acum = 0;
    memset(c,0, sizeof(int) * n);
    
    #define DIGIT(X) ((X/div) % base)

    for ( i = 0; i < n; i++)
    {
        c[DIGIT(v[i])]++;
    }
    
    for ( i = 0; i < base; i++)
    {
        t = c[i];
        c[i] = acum;
        acum += t;
    }
    
    for ( i = 0; i < n; i++)
    {
        s[c[DIGIT(v[i])]] = v[i];
        c[DIGIT(v[i])]++;
    }

    memcpy(v,s, sizeof(int) * n);
    
}

void RadixSort(int *v, int n){

    int k, div = 1;
    k = max(v,n);
    int *temp = malloc(sizeof(int)*n);
    while (k > 0)
    {
        counting_sort(v, n, div, 10, temp);
        div*=10;
        k/=10;
    }
    free(temp);
}