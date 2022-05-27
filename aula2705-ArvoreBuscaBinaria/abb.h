#pragma once

typedef struct ABB{
    int chave;
    struct ABB* esq;
    struct ABB* dir;
} ABB;

ABB* ABB_criar(int chave, ABB* esq, ABB*dir);
void ABB_inserir(ABB** a, int chave);
ABB* ABB_buscar(ABB* a, int chave);
void imprimir(ABB* a);