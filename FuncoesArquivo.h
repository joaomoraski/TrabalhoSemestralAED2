//
// Created by moraski on 02/12/2021.
//
#include <stdio.h>
#include "TAD_BufferSaida.h"
#include "TAD_BufferEntrada.h"

#ifndef FUNCOESARQUIVO_H
#define FUNCOESARQUIVO_H

void lerArquivoEntrada(const char *arquivoEntrada, BUFFERENTRADA *bufferEntrada, int qtdeRegistros);

void lerArquivoSaida(const char *arquivoEntrada, BUFFERSAIDA *bufferSaida, int qtdeRegistros);

long calculaTamanhoArquivo(const char *nomeArquivo);

#endif
