#include <stdlib.h>
#include <stdio.h>
#include "ilist.h"
#include "hashtable_ed.h"

int THED_Hash(THED* HT, int chave){
    return chave % HT->m;
}

THED* THED_Criar(int m, int alloc_step){
    THED* nova;
    nova = malloc(sizeof(THED));
    nova->m = m;
    //nova->n = 0;
    nova->t = malloc(sizeof(ILIST*) * m);
    for(int i = 0; i < m; i++){
        nova->t[i] = ILIST_Criar(10);
    }
    return nova;
}

void THED_Inserir(THED* HT, int chave, int valor){
    int h = THED_Hash(HT, chave);
    size_t tam_lista = ILIST_Tamanho(HT->t[h]);
    ILIST_Inserir(HT->t[h], chave, valor);
    if(tam_lista != ILIST_Tamanho(HT->t[h]))
        HT->n++;
}

void THED_Remover(THED* HT, int chave){
    int h = THED_Hash(HT, chave);
    size_t tam_lista = ILIST_Tamanho(HT->t[h]);
    ILIST_Remover(HT->t[h], chave);
    if(tam_lista != ILIST_Tamanho(HT->t[h]))
        HT->n--;
}

INOH* THED_Buscar(THED* HT, int chave){
    int h = THED_Hash(HT, chave);
    int p = ILIST_Buscar(HT->t[h], chave);
    return ILIST_Endereco(HT->t[h], p);
}

void THED_Imprimir(THED* HT){
        printf("===TABELA HASH M = %ld===\n", HT->m);
    for (int i = 0; i < HT->m; i++){
        printf("%d:\n", i);
        ILIST_Imprimir(HT->t[i], 0);
    }
    printf("===\n");
}

size_t THED_N(THED* HT){
    return HT->n;
}

ILIST* THED_Chaves(THED* HT){
    ILIST* s = ILIST_Criar(THED_N(HT) + 1);
    INOH* p = NULL;
    for(int i = 0; i < HT->m; i++){
        ILIST_Rebobinar(HT->t[i]);
        p = ILIST_Prox(HT->t[i]);
        while (p != NULL){
            ILIST_Inserir(s, p->chave, p->valor);
            p = ILIST_Prox(HT->t[1]);
        }
    }
    return s;
}

void THED_Destruir(THED* HT){

}
