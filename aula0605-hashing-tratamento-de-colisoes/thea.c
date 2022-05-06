#include "thea.h"

THEA *THEA_Criar(int m){
    THEA* nova;
    int i;
    nova = malloc(sizeof(THEA));
    nova->m = m;
    nova->t = malloc(sizeof(ELEM) * m);
    for(i = 0; i < m; i++)
        nova->t[i].estado = E_LIVRE;
    return nova;
}

int THEA_Hash(THEA* th, int chave, int k){
    return ((chave % th->m) + k) % th->m;
}


int THEA_Inserir(THEA* th, int chave, int valor){
    int k, h, h_inicial;
    k=0;
    h= THEA_Hash(th, chave, k);
    h_inicial=h;

    while(th->t[h].estado == E_OCUPADO){
        if(th->t[h].chave == chave)
            break;
        k++;
        h = THEA_Hash(th, chave, k);
        if (h == h_inicial)
            return -1;
    }
    th->t[h].chave = chave;
    th->t[h].valor = valor;
    th->t[h].estado = E_OCUPADO;
    return h;
}

void THEA_Imprimir(THEA* th){
    for(int i = 0; i < th->m; i++){
        printf("%2d: %d -> %d (%d)\n", i, th->t[i].chave, th->t[i].valor, th->t[i].estado);
    }
    printf("\n");
}