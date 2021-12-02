//
// Created by moraski on 02/12/2021.
//

#include <stdio.h>
#include "ItemVenda.h"

#ifndef TAD_BUFFERENTRADA_H
#define TAD_BUFFERENTRADA_H

// Estrutura de buffer retirada de algumas pesquisas sobre como funciona um buffer
typedef struct BUFFERENTRADA {
    int isLigado;
    int qtdeRegistros; // quantidade de registros possuidas pelo buffer
    int qtdeRegistrosTotal; // quantos registros o buffer ira ler
    int qtdeConsumidos; // quantos ele ja consumiu
    int qtdeConsumidosTotal;  // quantos ele ja consumiu em relacao ao total
    ITEM_VENDA* itensVenda; // lista de item venda
    FILE* arquivo;
} BUFFERENTRADA;

BUFFERENTRADA *criarBufferEntrada(int qtdeRegistrosPorParticao, const char *arquivo);
ITEM_VENDA* proxBufferEntrada(BUFFERENTRADA* bufferEntrada);
ITEM_VENDA* consumirBufferEntrada(BUFFERENTRADA* bufferEntrada, const char* arquivo);
int verificarVazioBuffEntrada(BUFFERENTRADA* bufferEntrada);
void destruirBufferEntrada(const char *arquivoEntrada, BUFFERENTRADA **vetorBufferEntrada, int qtdeBuffers);



#endif //TAD_BUFFERENTRADA_H
