#include "arn.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

ARN* ARN_Criar(){
    return NULL;
}

static ARN* ARN_NovoNo(int chave, int valor){
    ARN* novo = malloc(sizeof(ARN));
    novo->chave = chave;
    novo->valor = valor;
    novo->cor = C_VERMELHO;
    novo->dir = NULL;
    novo->esq = NULL;

    return novo;
}

static bool eh_vermelho(ARN *A){
    if(A==NULL)
        return false;
    //reutnr A->cor == C_VERMELHO ? true : false;
    return A->cor == C_VERMELHO;
}
static inline void inverter_cores(ARN* A){
    A->cor = C_VERMELHO;
    A->esq->cor = C_PRETO;
    A->dir->cor = C_PRETO;
}
static void rot_esq(ARN** A){
    ARN *h, *x;
    h = *A;
    x = h->dir;
    h->dir = x->esq;
    x->esq = h;
    x->cor = h->cor;
    h->cor = C_VERMELHO;
    *A = x;
}
static void rot_dir(ARN** A){
    ARN *h;
    ARN *x;
    h = *A;
    x = h->esq;
    h->esq = x->dir;
    x->dir = h;
    x->cor = h->cor;
    h->cor = C_VERMELHO;
    *A = x;
}

void ARN_Inserir(ARN **A, int chave, int valor){
    if ((*A) == NULL){
        *A = ARN_NovoNo(chave, valor);
        return;
    }
    if(chave < (*A)->chave){
        ARN_Inserir(&(*A)->esq, chave, valor);
    }
    else if(chave > (*A)->chave){
        ARN_Inserir(&(*A)->dir, chave, valor);
    }
    //inserção nó simples à dir e
    //inserção duplo valor mediano
    if(eh_vermelho((*A)->dir) && !eh_vermelho((*A)->esq)){
        rot_esq(A);
    }
    //inserção duplo menor valor
    //inserção duplo valor mediano
    if(eh_vermelho((*A)->esq) && eh_vermelho((*A)->esq->esq)){
        rot_dir(A);
    }
    //inserção dupla valor mediano
    //inserção duplo maior valor
    if(eh_vermelho((*A)->esq) && eh_vermelho((*A)->dir)){
        inverte_cores(*A);
    }
}

void ARN_Imprimir(ARN *A, int nivel, char lado){
    int i;
    for(i = 0; i < nivel; i++){
        printf("--> ");
    }
    if(A == NULL){
        printf("(%c) NONE\n", lado);
    }
    else{
        printf("(%c) %c [%s]\n", lado, (char)A->valor, A->cor == C_VERMELHO ? "V" : "P");
        ARN_Imprimir(A->esq, nivel+1, 'e');
        ARN_Imprimir(A->dir, nivel+1, 'd');
    }
}