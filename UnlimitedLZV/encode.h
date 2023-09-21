//
// Created by ash on 21.09.23.
//

#ifndef LZV_UNLIMITED_ENCODE_H
#define LZV_UNLIMITED_ENCODE_H

#include "Writer.h"
#include "int_code.h"

struct Node{
    Node* ch[257];

    unsigned long long code;
};

void encode(Reader &rd, Writer &wr);


#endif //LZV_UNLIMITED_ENCODE_H
