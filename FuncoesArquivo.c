//
// Created by moraski on 02/12/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "TAD_BufferEntrada.h"
#include "TAD_BufferSaida.h"
#include "FuncoesArquivo.h"

int contaNomeArqTemp(int numero) {
    int cont = 1;
    if (numero >= 10) {
        numero /= 10;
        cont += contaNomeArqTemp(numero);
    }
    return cont;
}

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

void addArq(ITEM_VENDA *temp, int numeroRegistros, int numeroParticoes) {
    char novoNomeArquivo[contaNomeArqTemp(numeroParticoes)];
    sprintf(novoNomeArquivo, "%d", numeroParticoes);
    FILE *novaParticao = fopen(novoNomeArquivo, "wb");
    fwrite(temp, sizeof(ITEM_VENDA), numeroRegistros, novaParticao);
    fclose(novaParticao);
}


int dividirArquivo(const char *arqEntrada, int qtdeRegPPart, int qtdeReg, long int tamanhoArquivo) {
    FILE *arq;
    ITEM_VENDA *temp;

    int qtdeParticoes = 0, qtdeElementos = 0, lidosSucesso = 0;
    long int tamanhoLido = 0;

    temp = (ITEM_VENDA *) malloc(qtdeReg * sizeof(ITEM_VENDA));
    arq = fopen(arqEntrada, "rb");

    while (!feof(arq)) {
        if (tamanhoArquivo - tamanhoLido < (qtdeRegPPart * sizeof(ITEM_VENDA)))
            qtdeRegPPart = ((tamanhoArquivo - tamanhoLido) / sizeof(ITEM_VENDA));

        if (qtdeRegPPart == 0) break;

        for (int i = 0; i < qtdeRegPPart; i++) {
            lidosSucesso = fread(&temp[i], sizeof(ITEM_VENDA), 1, arq);
            if (lidosSucesso == 0) return 0;
        }
        qsort(temp, qtdeRegPPart, sizeof(ITEM_VENDA), compare);
        addArq(temp, qtdeRegPPart, qtdeParticoes);
        tamanhoLido += qtdeRegPPart * sizeof(ITEM_VENDA);
        qtdeParticoes++;
    }
    fclose(arq);
    free(temp);
    return qtdeParticoes;
}


void ordenacaoExterna(const char *arqEntrada, long numeroMaximoBits, long numeroBitsBufferSaida, const char *arqSaida) {
    unsigned long tamanhoArquivo = calculaTamanhoArquivo(arqEntrada);
    long qtdeDivisoesEntrada = ceil((float) tamanhoArquivo / numeroMaximoBits);
    int qtdeReg = (tamanhoArquivo / sizeof(ITEM_VENDA));
    int qtdeRegPPart = ceil(qtdeReg / qtdeDivisoesEntrada);
    int novoQtdeDivisoesEntrada = dividirArquivo(arqEntrada, qtdeRegPPart, qtdeReg, tamanhoArquivo);
    BUFFERENTRADA **vetorBuffEntrada = (BUFFERENTRADA **) malloc(novoQtdeDivisoesEntrada * sizeof(BUFFERENTRADA *));
    BUFFERSAIDA *buffSaida = criarBufferSaida((numeroBitsBufferSaida / sizeof(ITEM_VENDA)), qtdeReg);

    char nomeArquivo[contaNomeArqTemp(novoQtdeDivisoesEntrada)];
    for (int i = 0; i < novoQtdeDivisoesEntrada; i++) {
        sprintf(nomeArquivo, "%d", i);
        vetorBuffEntrada[i] = criarBufferEntrada(qtdeRegPPart, nomeArquivo);
    }
    intercalacaoKVias(vetorBuffEntrada, novoQtdeDivisoesEntrada, qtdeReg, buffSaida, arqSaida);

    if (calculaTamanhoArquivo(arqEntrada) == calculaTamanhoArquivo(arqSaida))
        printf("Arquivo de entrada e saida possuem o mesmo tamanho.\n");

    // destruir arquivos e buffers
    destruirBufferSaida(buffSaida);
    destruirBufferEntrada(arqEntrada, vetorBuffEntrada, novoQtdeDivisoesEntrada);
};