#include "abb.h"
#include <stdio.h>

int main(int argc, char** argv){
    ABB* r = NULL;
    ABB_inserir(&r, 10);
    ABB_inserir(&r, 4);
    ABB_inserir(&r, 20);
    ABB_inserir(&r, 2);
    ABB_inserir(&r, 6);
    ABB_inserir(&r, 1);
    ABB_inserir(&r, 3);

    printf("%p\n", ABB_buscar(r, 1));
    printf("%p\n", ABB_buscar(r, 7));
    printf("%p\n", ABB_buscar(r, 2));
    printf("%p\n", ABB_buscar(r, 20));
    printf("%p\n", ABB_buscar(r, 8));
    imprimir(r);
    return 0;
}