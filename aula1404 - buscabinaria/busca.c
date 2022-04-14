#include "busca.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define DEBUG 1
void print_subarray(int *v, int e, int d){
    int i;
    for(i=e; i<=d; i++)
        printf("%d ", v[i]);
}

static int busca_bin(int *v, int e, int d, int x){
    if (e<=d){
        #if DEBUG
        print_subarray(v,e,d);
        printf("\n");
        #endif
        int m = (e+d)/2;
        if (x == v[m])
        return m;
        else if (v[m] > x)
            return busca_bin(v, e, m-1, x);
        else if (v[m] < x)
            return busca_bin(v, m+1, d, x);
    }
    return -1;
}
int BuscaBinaria(int *v, int n, int x){
    return busca_bin(v, 0, n-1, x);
}