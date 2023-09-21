//
// Created by ash on 21.09.23.
//

#include <iostream>
#include "encode.h"

void encode(Reader &rd, Writer &wr) {
    Node *root = new Node;
    for (int i = 1; i <= 256; i++) {
        root->ch[i] = new Node{{nullptr}, static_cast<unsigned long long>(i)};
    }
    unsigned long long code = 256;
    Node *curr = root;
    char t;
    while (rd.get_byte(t)) {
        if (curr->ch[((unsigned char) t) + 1]) {
            curr = curr->ch[(unsigned char) t + 1];
        } else {
            //std::cout << curr->code << " ";
            for (bool el: delta_elias(curr->code)) {
                wr.set_bit(el);
            }
            curr->ch[(unsigned char) t + 1] = new Node{{nullptr}, ++code};
            curr = root->ch[(unsigned char) t + 1];
        }
    }
    if (curr != root) {
        std::cout << curr->code << " ";
        for (bool el: delta_elias(curr->code)) {
            wr.set_bit(el);
        }
    }
}
