//
// Created by moraski on 02/12/2021.
//
#include <stdio.h>
#include <stdlib.h>

#include "TAD_BufferEntrada.h"
#include "TAD_BufferSaida.h"

long calculaTamanhoArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    rewind(arquivo);
    fclose(arquivo);
    return tamanho;
}

void lerArquivoEntrada(const char *arquivoEntrada, BUFFERENTRADA *bufferEntrada, int qtdeRegistros) {
    if (bufferEntrada->qtdeRegistrosTotal == 0) return;
    ITEM_VENDA *itensVenda = (ITEM_VENDA *) malloc(qtdeRegistros * sizeof(ITEM_VENDA));
    for (int i = 0; i < qtdeRegistros; i++) fread(&itensVenda[i], sizeof(ITEM_VENDA), 1, bufferEntrada->arquivo);
    bufferEntrada->itensVenda = itensVenda;
    fclose(bufferEntrada->arquivo);
}

// Caso necessário
void lerArquivoSaida(const char *arquivoEntrada, BUFFERSAIDA *bufferSaida, int qtdeRegistros) {
    if (bufferSaida->qtdeRegistrosTotal == 0) return;
    ITEM_VENDA *itensVenda = (ITEM_VENDA *) malloc(qtdeRegistros * sizeof(ITEM_VENDA));
    for (int i = 0; i < qtdeRegistros; i++) fread(&itensVenda[i], sizeof(ITEM_VENDA), 1, bufferSaida->arquivo);
    bufferSaida->itensVenda = itensVenda;
    fclose(bufferSaida->arquivo);
}