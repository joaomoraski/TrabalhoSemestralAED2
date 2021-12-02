//
// Created by moraski on 02/12/2021.
//
#include <stdio.h>
#include "ItemVenda.h"

#ifndef TAD_BUFFERSAIDA_H
#define TAD_BUFFERSAIDA_H

// Estrutura de buffer retirada de algumas pesquisas sobre como funciona um buffer
typedef struct BUFFERSAIDA{
    int isLigado;
    int qtdeRegistros; // quantidade de registros possuidas pelo buffer
    int qtdeRegistrosTotal; // quantos registros o buffer ira ler
    int qtdeConsumidos; // quantos ele ja consumiu
    int qtdeConsumidosTotal;  // quantos ele ja consumiu em relacao ao total
    ITEM_VENDA* itensVenda; // lista de item venda
    FILE* arquivo;
} BUFFERSAIDA;

BUFFERSAIDA* criarBufferSaida(int tam, int qtdeRegistros);
void inserirBufferSaida(BUFFERSAIDA* bufferSaida , ITEM_VENDA* itemVenda);
void despejarBufferSaida(BUFFERSAIDA* bufferSaida, FILE* nomeArquivo);
void destruirBufferSaida(BUFFERSAIDA* bufferSaida);


#endif
