//
// Created by moraski on 02/12/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TAD_BufferEntrada.h"
#include "FuncoesArquivo.h"

BUFFERENTRADA *criarBufferEntrada(int qtdeRegistrosPorParticao, const char *arquivo) {
    long tamanhoArquivo = calculaTamanhoArquivo(arquivo);

    BUFFERENTRADA *bufferEntrada = (BUFFERENTRADA *) malloc(sizeof(BUFFERENTRADA));

    bufferEntrada->arquivo = fopen(arquivo, "rb");
    bufferEntrada->qtdeConsumidos = 0;
    bufferEntrada->qtdeConsumidosTotal = 0;
    bufferEntrada->qtdeRegistros = qtdeRegistrosPorParticao;
    bufferEntrada->qtdeRegistrosTotal = tamanhoArquivo / sizeof(ITEM_VENDA);
    bufferEntrada->isLigado = 1;

    // preencher o vetor de itens venda usando o arquivo gerado pelo gerador disponibilizado
    lerArquivoEntrada(arquivo, bufferEntrada, qtdeRegistrosPorParticao);

    return bufferEntrada;
}

ITEM_VENDA *proxBufferEntrada(BUFFERENTRADA *bufferEntrada) { return &bufferEntrada->itensVenda[bufferEntrada->qtdeConsumidos]; }

ITEM_VENDA *consumirBufferEntrada(BUFFERENTRADA *bufferEntrada, const char *arquivo) {
    if (bufferEntrada == NULL || bufferEntrada->isLigado == 0) return NULL;
    if (verificarVazioBuffEntrada(bufferEntrada) == 1) {
        lerArquivoEntrada(arquivo, bufferEntrada, bufferEntrada->qtdeConsumidos);
        bufferEntrada->qtdeConsumidos = 0;
    }
    bufferEntrada->qtdeConsumidos++;
    bufferEntrada->qtdeConsumidosTotal++;
    if (bufferEntrada->qtdeConsumidosTotal == bufferEntrada->qtdeRegistrosTotal) bufferEntrada->isLigado = 0;
    return &bufferEntrada->itensVenda[bufferEntrada->qtdeConsumidos - 1];
}

int verificarVazioBuffEntrada(BUFFERENTRADA *bufferEntrada) { return bufferEntrada->qtdeConsumidos == bufferEntrada->qtdeRegistros ? 1 : 0; }

int destruirArquivos(const char *arq){ return remove(arq); }

void destruirBufferEntrada(const char *arquivoEntrada, BUFFERENTRADA **vetorBufferEntrada, int qtdeBuffers) {
    if (vetorBufferEntrada == NULL) return;
    if (arquivoEntrada == NULL) return;
    if (qtdeBuffers == 0) return;
    for (int i = 0; i < qtdeBuffers; i++) {
        char nomeArquivoPart[contaNomeArqTemp(qtdeBuffers)];
        sprintf(nomeArquivoPart, "%d", i);
        destruirArquivos(nomeArquivoPart);
        free(vetorBufferEntrada[i]->itensVenda);
        free(vetorBufferEntrada[i]);
    }
    free(vetorBufferEntrada);
    remove(arquivoEntrada);
}