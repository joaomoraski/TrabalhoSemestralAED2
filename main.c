//
// Created by moraski on 02/12/2021.
//
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include "FuncoesArquivo.h"
#include "TAD_BufferEntrada.h"
#include "TAD_BufferSaida.h"
#include "big_file.h"

#define QtdeReg1 256000
#define QtdeReg2 512000
#define QtdeReg3 921600
#define QtdeReg4 1572864
#define MaximoBits01 8388608
#define MaximoBits02 16777216 // mesmo para 1 da 2 tabela
#define MaximoBits03 33554432 // mesmo para o 2 da 2 tabela
#define MaximoBits04 67108864 // 1 da tabela 3 e 4 tbm
#define MaximoBits05 134217728 // tabela 04 e 03
#define MaximoBits06 268435456 // tabela 04 e 03



int main() {

    // ================================================================= PROXIMO =================================================================
    clock_t t = clock();\
    printf("========================= Ordenacao com 256000 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg1, 42);
    printf("========================= Tamanho maximo de bits %d - B/8 =========================\n", MaximoBits01);
    long numeroMaximoBits = MaximoBits01;
    long numeroBitsBufferSaida = numeroMaximoBits/8;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 256000 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg1, 42);
    printf("========================= Tamanho maximo de bits %d - B/4 =========================\n", MaximoBits01);
    numeroMaximoBits = MaximoBits01;
    numeroBitsBufferSaida = numeroMaximoBits/4;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 256000 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg1, 42);
    printf("========================= Tamanho maximo de bits %d - B/2 =========================\n", MaximoBits01);
    numeroMaximoBits = MaximoBits01;
    numeroBitsBufferSaida = numeroMaximoBits/2;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    // ================================================================= MAXIMO BITS 02 =================================================================
    t = clock();\
    printf("========================= Ordenacao com 256000 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg1, 42);
    printf("========================= Tamanho maximo de bits %d - B/8 =========================\n", MaximoBits02);
    numeroMaximoBits = MaximoBits02;
    numeroBitsBufferSaida = numeroMaximoBits/8;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 256000 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg1, 42);
    printf("========================= Tamanho maximo de bits %d - B/4 =========================\n", MaximoBits02);
    numeroMaximoBits = MaximoBits02;
    numeroBitsBufferSaida = numeroMaximoBits/4;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 256000 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg1, 42);
    printf("========================= Tamanho maximo de bits %d - B/2 =========================\n", MaximoBits02);
    numeroMaximoBits = MaximoBits02;
    numeroBitsBufferSaida = numeroMaximoBits/2;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);


    // ================================================================= PROXIMO =================================================================
    // ================================================================= MAXIMO BITS 03 =================================================================
    t = clock();\
    printf("========================= Ordenacao com 256000 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg1, 42);
    printf("========================= Tamanho maximo de bits %d - B/8 =========================\n", MaximoBits03);
    numeroMaximoBits = MaximoBits03;
    numeroBitsBufferSaida = numeroMaximoBits/8;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 256000 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg1, 42);
    printf("========================= Tamanho maximo de bits %d - B/4 =========================\n", MaximoBits03);
    numeroMaximoBits = MaximoBits03;
    numeroBitsBufferSaida = numeroMaximoBits/4;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 256000 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg1, 42);
    printf("========================= Tamanho maximo de bits %d - B/2 =========================\n", MaximoBits03);
    numeroMaximoBits = MaximoBits03;
    numeroBitsBufferSaida = numeroMaximoBits/2;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);


    // ================================================================= PROXIMO =================================================================
    // ================================================================= MAXIMO BITS 02 =================================================================
    t = clock();\
    printf("========================= Ordenacao com 512000 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg2, 42);
    printf("========================= Tamanho maximo de bits %d - B/8 =========================\n", MaximoBits02);
    numeroMaximoBits = MaximoBits02;
    numeroBitsBufferSaida = numeroMaximoBits/8;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 512000 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg2, 42);
    printf("========================= Tamanho maximo de bits %d - B/4 =========================\n", MaximoBits02);
    numeroMaximoBits = MaximoBits02;
    numeroBitsBufferSaida = numeroMaximoBits/4;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 512000 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg2, 42);
    printf("========================= Tamanho maximo de bits %d - B/2 =========================\n", MaximoBits02);
    numeroMaximoBits = MaximoBits02;
    numeroBitsBufferSaida = numeroMaximoBits/2;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);


    // ================================================================= PROXIMO =================================================================
    // ================================================================= MAXIMO BITS 03 =================================================================
    t = clock();\
    printf("========================= Ordenacao com 512000 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg2, 42);
    printf("========================= Tamanho maximo de bits %d - B/8 =========================\n", MaximoBits03);
    numeroMaximoBits = MaximoBits03;
    numeroBitsBufferSaida = numeroMaximoBits/8;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 512000 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg2, 42);
    printf("========================= Tamanho maximo de bits %d - B/4 =========================\n", MaximoBits03);
    numeroMaximoBits = MaximoBits03;
    numeroBitsBufferSaida = numeroMaximoBits/4;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 512000 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg2, 42);
    printf("========================= Tamanho maximo de bits %d - B/2 =========================\n", MaximoBits03);
    numeroMaximoBits = MaximoBits03;
    numeroBitsBufferSaida = numeroMaximoBits/2;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    // ================================================================= MAXIMO BITS 03 =================================================================
    t = clock();\
    printf("========================= Ordenacao com 512000 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg1, 42);
    printf("========================= Tamanho maximo de bits %d - B/8 =========================\n", MaximoBits04);
    numeroMaximoBits = MaximoBits04;
    numeroBitsBufferSaida = numeroMaximoBits/8;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 512000 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg2, 42);
    printf("========================= Tamanho maximo de bits %d - B/4 =========================\n", MaximoBits04);
    numeroMaximoBits = MaximoBits04;
    numeroBitsBufferSaida = numeroMaximoBits/4;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 512000 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg2, 42);
    printf("========================= Tamanho maximo de bits %d - B/2 =========================\n", MaximoBits04);
    numeroMaximoBits = MaximoBits04;
    numeroBitsBufferSaida = numeroMaximoBits/2;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);


    // ================================================================= PROXIMO =================================================================
    // ================================================================= MAXIMO BITS 04 =================================================================
    t = clock();\
    printf("========================= Ordenacao com 921600 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg3, 42);
    printf("========================= Tamanho maximo de bits %d - B/8 =========================\n", MaximoBits04);
    numeroMaximoBits = MaximoBits04;
    numeroBitsBufferSaida = numeroMaximoBits/8;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 921600 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg3, 42);
    printf("========================= Tamanho maximo de bits %d - B/4 =========================\n", MaximoBits04);
    numeroMaximoBits = MaximoBits04;
    numeroBitsBufferSaida = numeroMaximoBits/4;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 921600 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg3, 42);
    printf("========================= Tamanho maximo de bits %d - B/2 =========================\n", MaximoBits04);
    numeroMaximoBits = MaximoBits04;
    numeroBitsBufferSaida = numeroMaximoBits/2;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);


    // ================================================================= PROXIMO =================================================================
    // ================================================================= MAXIMO BITS 05 =================================================================
    t = clock();\
    printf("========================= Ordenacao com 921600 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg3, 42);
    printf("========================= Tamanho maximo de bits %d - B/8 =========================\n", MaximoBits05);
    numeroMaximoBits = MaximoBits05;
    numeroBitsBufferSaida = numeroMaximoBits/8;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 921600 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg3, 42);
    printf("========================= Tamanho maximo de bits %d - B/4 =========================\n", MaximoBits05);
    numeroMaximoBits = MaximoBits05;
    numeroBitsBufferSaida = numeroMaximoBits/4;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 921600 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg3, 42);
    printf("========================= Tamanho maximo de bits %d - B/2 =========================\n", MaximoBits05);
    numeroMaximoBits = MaximoBits05;
    numeroBitsBufferSaida = numeroMaximoBits/2;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    // ================================================================= MAXIMO BITS 06 =================================================================
    t = clock();\
    printf("========================= Ordenacao com 921600 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg3, 42);
    printf("========================= Tamanho maximo de bits %d - B/8 =========================\n", MaximoBits06);
    numeroMaximoBits = MaximoBits06;
    numeroBitsBufferSaida = numeroMaximoBits/8;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 921600 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg3, 42);
    printf("========================= Tamanho maximo de bits %d - B/4 =========================\n", MaximoBits06);
    numeroMaximoBits = MaximoBits06;
    numeroBitsBufferSaida = numeroMaximoBits/4;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 921600 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg3, 42);
    printf("========================= Tamanho maximo de bits %d - B/2 =========================\n", MaximoBits06);
    numeroMaximoBits = MaximoBits06;
    numeroBitsBufferSaida = numeroMaximoBits/2;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);



    // ================================================================= PROXIMO =================================================================
    // ================================================================= MAXIMO BITS 04 =================================================================
    t = clock();\
    printf("========================= Ordenacao com 1572864 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg4, 42);
    printf("========================= Tamanho maximo de bits %d - B/8 =========================\n", MaximoBits04);
    numeroMaximoBits = MaximoBits04;
    numeroBitsBufferSaida = numeroMaximoBits/8;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 1572864 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg4, 42);
    printf("========================= Tamanho maximo de bits %d - B/4 =========================\n", MaximoBits04);
    numeroMaximoBits = MaximoBits04;
    numeroBitsBufferSaida = numeroMaximoBits/4;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 1572864 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg4, 42);
    printf("========================= Tamanho maximo de bits %d - B/2 =========================\n", MaximoBits04);
    numeroMaximoBits = MaximoBits04;
    numeroBitsBufferSaida = numeroMaximoBits/2;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);


    // ================================================================= PROXIMO =================================================================
    // ================================================================= MAXIMO BITS 05 =================================================================
    t = clock();\
    printf("========================= Ordenacao com 1572864 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg4, 42);
    printf("========================= Tamanho maximo de bits %d - B/8 =========================\n", MaximoBits05);
    numeroMaximoBits = MaximoBits05;
    numeroBitsBufferSaida = numeroMaximoBits/8;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 1572864 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg4, 42);
    printf("========================= Tamanho maximo de bits %d - B/4 =========================\n", MaximoBits05);
    numeroMaximoBits = MaximoBits05;
    numeroBitsBufferSaida = numeroMaximoBits/4;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 1572864 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg4, 42);
    printf("========================= Tamanho maximo de bits %d - B/2 =========================\n", MaximoBits05);
    numeroMaximoBits = MaximoBits05;
    numeroBitsBufferSaida = numeroMaximoBits/2;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);


    // ================================================================= PROXIMO =================================================================
    // ================================================================= MAXIMO BITS 06 =================================================================
    t = clock();\
    printf("========================= Ordenacao com 1572864 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg4, 42);
    printf("========================= Tamanho maximo de bits %d - B/8 =========================\n", MaximoBits06);
    numeroMaximoBits = MaximoBits06;
    numeroBitsBufferSaida = numeroMaximoBits/8;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 1572864 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg4, 42);
    printf("========================= Tamanho maximo de bits %d - B/4 =========================\n", MaximoBits06);
    numeroMaximoBits = MaximoBits06;
    numeroBitsBufferSaida = numeroMaximoBits/4;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    // ================================================================= PROXIMO =================================================================
    t = clock();
    printf("========================= Ordenacao com 1572864 registros =========================\n");
    gerar_array_iv("entrada.dat", QtdeReg4, 42);
    printf("========================= Tamanho maximo de bits %d - B/2 =========================\n", MaximoBits06);
    numeroMaximoBits = MaximoBits06;
    numeroBitsBufferSaida = numeroMaximoBits/2;
    ordenacaoExterna("entrada.dat", numeroMaximoBits, numeroBitsBufferSaida, "saida.dat");
    t = clock() - t;
    printf("Tempo necessário: %f segundos\n",((float)t)/CLOCKS_PER_SEC);

    return 0;
}