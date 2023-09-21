//
// Created by ash on 21.09.23.
//

#ifndef LZV_LIMITED_DECODE_H
#define LZV_LIMITED_DECODE_H

#include "Reader.h"
#include "Writer.h"
#include<vector>
#include<iostream>

unsigned long long get_n_bit_int(Reader &rd, int n);

void decode(Reader &rd, Writer &wr);


#endif //LZV_LIMITED_DECODE_H
