#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "ordenacao.h"

void trocar(int*v, int i, int j){
    int x = v[i];
    v[i] = v[j];
    v[j] = x; 
}
int partition (int*v, int p, int r){
    int x;
    int i, j;
    x=v[r];
    i = p-1;
    for (j=p;j<r;j++){
        if(v[j] <= x){
            i++;
            trocar(v,i,j);
        }
    }
    trocar(v,i+1,r);
    return i+1;
}

void QuickSort(int *v, int e, int d){
    if (e<d){
        int q = partition(v,e,d);
        QuickSort(v,e,q-1);
        QuickSort(v,q+1,d);
    }
}
