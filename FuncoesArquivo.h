//
// Created by moraski on 02/12/2021.
//
#include <stdio.h>
#include "TAD_BufferSaida.h"
#include "TAD_BufferEntrada.h"
#include "Ordenacao.h"

#ifndef FUNCOESARQUIVO_H
#define FUNCOESARQUIVO_H

void lerArquivoEntrada(const char *arquivoEntrada, BUFFERENTRADA *bufferEntrada, int qtdeRegistros);

void lerArquivoSaida(const char *arquivoEntrada, BUFFERSAIDA *bufferSaida, int qtdeRegistros);

long calculaTamanhoArquivo(const char *nomeArquivo);

void ordenacaoExterna(const char *arqEntrada, long numeroMaximoBits, long numeroBitsBufferSaida, const char *arqSaida);

int dividirArquivo(const char *arqEntrada, int qtdeRegPPart, int qtdeReg, long int tamanhoArquivo);

void addArq(ITEM_VENDA *temp, int numeroRegistros, int numeroParticoes);

int contaNomeArqTemp(int numero);

#endif
