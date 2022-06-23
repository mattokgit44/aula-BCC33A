#include "abb.h"
#include <stdio.h>
#include <stdlib.h>

int* gerar_vetor_aleatorio(int n, int seed, int max){
    int* v = malloc(sizeof(int) * n);
    srand(seed);
    for(int i = 0; i < n; i++){
        v[i] = rand() % max;
    }
    return v;
}

int main(int argc, char** argv){
    ABB* r = NULL;
    ABB_Inserir(&r, 5);
    ABB_Inserir(&r, 3);
    ABB_Inserir(&r, 1);
    ABB_Inserir(&r, 4);
    ABB_Inserir(&r, 2);
    ABB_Inserir(&r, 6);


    printf("%d\n", ABB_N(r));
    printf("%d\n", ABB_Altura(r));
}
