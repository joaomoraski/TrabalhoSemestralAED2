//
// Created by moraski on 02/12/2021.
//
#include <stdio.h>
#include <stdlib.h>

#include "TAD_BufferSaida.h"

BUFFERSAIDA *criarBufferSaida(int tam, int qtdeRegistros) {
    BUFFERSAIDA *bufferSaida = (BUFFERSAIDA *) malloc(sizeof(BUFFERSAIDA));
    bufferSaida->isLigado = 1;
    bufferSaida->itensVenda = (ITEM_VENDA *) malloc(tam * sizeof(ITEM_VENDA));
    bufferSaida->qtdeConsumidos = 0;
    bufferSaida->qtdeConsumidosTotal = 0;
    bufferSaida->qtdeRegistros = tam;
    bufferSaida->qtdeRegistrosTotal = qtdeRegistros;
    return bufferSaida;
}

void inserirBufferSaida(BUFFERSAIDA *bufferSaida, ITEM_VENDA *itemVenda) {
    bufferSaida->itensVenda[bufferSaida->qtdeConsumidos++] = *itemVenda;
    bufferSaida->qtdeConsumidosTotal++;
}

void despejarBufferSaida(BUFFERSAIDA *bufferSaida, FILE *nomeArquivo) {
    for (int i = 0; i < bufferSaida->qtdeConsumidos; ++i) fwrite(&bufferSaida->itensVenda[i], sizeof(ITEM_VENDA), 1, nomeArquivo);
    bufferSaida->qtdeConsumidos = 0;
}

void destruirBufferSaida(BUFFERSAIDA *bufferSaida) {
    free(bufferSaida->itensVenda);
    free(bufferSaida);
}
