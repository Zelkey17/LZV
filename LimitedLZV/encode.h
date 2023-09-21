//
// Created by ash on 21.09.23.
//

#ifndef LZV_LIMITED_ENCODE_H
#define LZV_LIMITED_ENCODE_H

#include "Writer.h"
#include "Reader.h"

struct Node {
    Node *ch[257]={nullptr};

    unsigned long long code;

    ~Node() {
        for (auto el: ch) {
            if (el)delete el;
        }
    }
};

void encode(Reader &reader, Writer &writer);


#endif //LZV_LIMITED_ENCODE_H
