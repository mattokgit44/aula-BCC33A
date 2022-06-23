#include <stdlib.h>
#include <stdio.h>
#include "abb.h"

ABB* ABB_Criar(int chave, ABB* esq, ABB* dir){
    ABB* novo = malloc(sizeof(ABB));
    novo->chave = chave;
    novo->dir = dir;
    novo->esq = esq;
    return novo;
}

void ABB_Inserir(ABB** A, int chave){
    if((*A) == NULL){
        *A = ABB_Criar(chave, NULL, NULL);
        return;
    }
    if(chave == (*A)->chave){
        return;
    }else if(chave < (*A)->chave){
        ABB_Inserir(&(*A)->esq, chave);
    }else
        ABB_Inserir(&(*A)->dir, chave);
}

ABB* ABB_Buscar(ABB *A, int chave){
    if(A == NULL){
        return NULL;
    }
    if(A->chave == chave){
        return A;
    }
    if(chave < A->chave){
        return ABB_Buscar(A->esq, chave);
    }
    return ABB_Buscar(A->dir, chave);
}

void ABB_ImprimirEmOrdem(ABB *A){
    if(A == NULL)
        return;
    ABB_ImprimirEmOrdem(A->esq);
    printf("%d, ", A->chave);
    ABB_ImprimirEmOrdem(A->dir);
}
//void ABB_Count(ABB *A, int *qtd){
//    if(A==NULL)
//        return;
//    ABB_Count(A->esq, qtd);
//    ABB_Count(A->dir, qtd);
//    *qtd += 1;
//}
//int ABB_N(ABB *A){
//    int qtd = 0;
//    ABB_Count(A, &qtd);
//    return qtd;
//}
int ABB_N(ABB *A){
    if(A == NULL) return 0;
    return 1+ABB_N(A->esq)+ABB_N(A->dir);
}
int ABB_Altura(ABB *A){
    if (A==NULL) return 0;
    return 1 + (ABB_Altura(A->esq) > ABB_Altura(A->dir) ? ABB_Altura(A->esq):ABB_Altura(A->dir));
}
