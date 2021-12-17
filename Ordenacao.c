//
// Created by moraski on 16/12/2021.
//
#include "math.h"
#include "stdlib.h"
#include "FuncoesArquivo.h"
#include "Ordenacao.h"

static int getMenorValor(BUFFERENTRADA **vetorBuffEntrada, int qtdeBuffEntrada) {
    ITEM_VENDA proximo, menor;
    int posicao;

    for (int i = 0;
         i < qtdeBuffEntrada; i++) {
        if (vetorBuffEntrada[i]->isLigado == 1) {
            menor = *proxBufferEntrada(vetorBuffEntrada[i]);
            posicao = i;
            break;
        }
    }

    for (int i = posicao;
         i < qtdeBuffEntrada; i++) {
        if (vetorBuffEntrada[i]->isLigado == 1) {
            proximo = *proxBufferEntrada(vetorBuffEntrada[i]);
            if (proximo.id < menor.id) {
                menor = proximo;
                posicao = i;
            }
        }
    }
    return posicao;
}


void intercalacaoKVias(BUFFERENTRADA **vetorBuffEntrada, int qtdeBuffEntrada, int qtdeReg, BUFFERSAIDA *buffSaida,
                             const char *arqSaida) {

    FILE *arqSaidaAberto = fopen(arqSaida, "wb");
    int posicaoMenorValor;

    ITEM_VENDA *consumido;

    for (int i = 0; i < qtdeReg; i++) {
        posicaoMenorValor = getMenorValor(vetorBuffEntrada, qtdeBuffEntrada);

        inserirBufferSaida(buffSaida,
                           &vetorBuffEntrada[posicaoMenorValor]->itensVenda[vetorBuffEntrada[posicaoMenorValor]->qtdeConsumidos]);

        char nomeArq[contaNomeArqTemp(qtdeBuffEntrada)];
        sprintf(nomeArq, "%d", posicaoMenorValor);
        consumido = consumirBufferEntrada(vetorBuffEntrada[posicaoMenorValor], nomeArq);

        if (buffSaida->qtdeConsumidos == buffSaida->qtdeRegistros ||
            buffSaida->qtdeConsumidosTotal == buffSaida->qtdeRegistrosTotal)
            despejarBufferSaida(buffSaida, arqSaidaAberto);

        if (i != consumido->id) return;
    }
    fclose(arqSaidaAberto);
}


int compare(const void *a, const void *b) {
    ITEM_VENDA *A = (ITEM_VENDA *) a;
    ITEM_VENDA *B = (ITEM_VENDA *) b;
    return (A->id - B->id);
}
