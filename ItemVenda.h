//
// Created by moraski on 02/12/2021.
//

#ifndef ITEMVENDA_H
#define ITEMVENDA_H

#include <stdint.h>

typedef struct ITEM_VENDA{
    uint32_t id;
    uint32_t id_venda;
    uint32_t data;
    float desconto;
    char obs[1008];
}ITEM_VENDA;

#endif //ITEMVENDA_H
