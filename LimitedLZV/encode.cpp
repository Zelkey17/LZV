//
// Created by ash on 21.09.23.
//

#include <iostream>
#include "encode.h"

void encode(Reader &reader, Writer &writer) {
    Node *root = new Node;
    for (unsigned int i = 1; i <= 256; i++) {
        root->ch[i] = new Node{{nullptr}, i};
    }
    unsigned long long code = 256;
    Node *curr = root;
    unsigned char inputChar;
    while (reader.get_byte(inputChar)) {
        if (curr->ch[inputChar + 1]) {
            curr = curr->ch[inputChar + 1];
        } else {
            //std::cout << curr->code << " ";
            for (int i = (int) std::__lg(code); i >= 0; i--) {
                writer.set_bit(curr->code & (1 << i));
            }
            if (code == (1 << 16) - 1) {
                delete root;
                encode(reader, writer);
                return;
            } else {
                curr->ch[inputChar + 1] = new Node{{nullptr}, ++code};
            }

            curr = root->ch[inputChar + 1];
        }
    }
    if (curr != root) {
        //std::cout << curr->code << " ";
        for (int i = (int) std::__lg(code); i >= 0; i--) {
            writer.set_bit(curr->code & (1 << i));
        }
    }
}