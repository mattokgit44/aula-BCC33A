#pragma once

typedef struct ABB{
    int chave;
    struct ABB* esq;
    struct ABB* dir;
} ABB;

ABB* ABB_Criar(int chave, ABB* esq, ABB* dir);
void ABB_Inserir(ABB** A, int chave);
ABB* ABB_Buscar(ABB *A, int chave);
void ABB_ImprimirEmOrdem(ABB *A);
int ABB_N(ABB *A);
int ABB_Altura(ABB *A);