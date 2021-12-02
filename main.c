//
// Created by moraski on 02/12/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include "FuncoesArquivo.h"
#include "TAD_BufferEntrada.h"
#include "TAD_BufferSaida.h"

int main() {

    clock_t t = clock();

    const char *nomeArquivo = "entrada01.dat";
    long tamanhoArquivo = calculaTamanhoArquivo(nomeArquivo);
    long qtdeBuffers = ceil((float) tamanhoArquivo / 8388608);
    int qtdeRegistros = (tamanhoArquivo / sizeof(ITEM_VENDA));
    int qtdeRegistrosPorParticao = ceil(qtdeRegistros / qtdeBuffers);


    printf("Criando buffer de entrada\n");
    BUFFERENTRADA *bufferEntrada = criarBufferEntrada(qtdeRegistrosPorParticao, nomeArquivo);
    printf("Criou buffer de entrada\n");
    ITEM_VENDA *itemVenda = proxBufferEntrada(bufferEntrada);
    printf("Proximo Buffer: %lu\n", (unsigned long) itemVenda->id);
    ITEM_VENDA *consumido = consumirBufferEntrada(bufferEntrada, nomeArquivo);
    printf("Consumido id: %lu\n", (unsigned long) consumido->id);
    printf("Ta vazio: %d\n", verificarVazioBuffEntrada(bufferEntrada));

    t = clock() - t;

    printf("%f segundos\n",((float)t)/CLOCKS_PER_SEC);
    return 0;
}