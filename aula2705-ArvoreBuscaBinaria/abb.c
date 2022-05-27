#include "abb.h"
#include <stdlib.h>
#include <stdio.h>

ABB* ABB_criar(int chave, ABB* esq, ABB* dir){
    ABB* novo = malloc(sizeof(ABB));
    novo->chave = chave;
    novo->esq = esq;
    novo->dir = dir;
    return novo;
}
void ABB_inserir(ABB** a, int chave){
    if((*a) == NULL){
        *a = ABB_criar(chave, NULL, NULL);
        return;
    }
    if(chave <= (*a)->chave)
        ABB_inserir(&(*a)->esq, chave);
    else
        ABB_inserir(&(*a)->dir, chave);
}
ABB* ABB_buscar(ABB* a, int chave){
    if(a == NULL)
        return NULL;
    if(a->chave == chave)
        return a;
    if(chave <= a->chave)
        ABB_buscar(a->esq, chave);
    else
        ABB_buscar(a->dir, chave);
}
void imprimir(ABB* a){
    if(a->esq != NULL)
        imprimir(a->esq);
    printf("%d\n", a->chave);
    if(a->dir != NULL)
        imprimir(a->dir);
}