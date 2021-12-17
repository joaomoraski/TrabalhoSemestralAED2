//
// Created by moraski on 16/12/2021.
//

#ifndef ORDENACAO_H
#define ORDENACAO_H
#include "FuncoesArquivo.h"

int compare(const void * a, const void * b);
void intercalacaoKVias(BUFFERENTRADA **vetorBuffEntrada, int qtdeBuffEntrada, int qtdeReg, BUFFERSAIDA* buffSaida, const char* arqSaida);

#endif
