//
// Created by moraski on 02/12/2021.
//
#include <stdio.h>
#include "TAD_BufferSaida.h"
#include "TAD_BufferEntrada.h"

#ifndef FUNCOESARQUIVO_H
#define FUNCOESARQUIVO_H

//int Conta_digitos(int N);
//BUFFER *Iniciar_Buffer();
void lerArquivoEntrada(const char *arquivoEntrada, BUFFERENTRADA *bufferEntrada, int qtdeRegistros);

void lerArquivoSaida(const char *arquivoEntrada, BUFFERSAIDA *bufferSaida, int qtdeRegistros);

long calculaTamanhoArquivo(const char *nomeArquivo);

//int Dividir_Arquivo(const char *arquivo_entrada, int quantidade_registros_por_particao, int quantidade_registros, long int tamanho_arquivo);
//void Ordenacao_Externa(const char *arquivo_entrada, long b, long s, const char *arquivo_saida);


#endif
