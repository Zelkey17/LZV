//
// Created by ash on 21.09.23.
//

#include "decode.h"

void decode(Reader &rd, Writer &wr) {
    std::vector<std::vector<unsigned char>> arr(1);
    for (int i = 1; i <= 256; i++) {
        arr.push_back({(unsigned char) i});
    }
    unsigned long long last_code = from_delta_elias(rd);
    for (unsigned char el: arr[last_code]) {
        wr.set_byte(el-1);
    }
    unsigned long long nc;
    while (nc = from_delta_elias(rd)) {
        if (nc == arr.size()) {
            std::vector<unsigned char> k = arr[last_code];
            k.push_back(arr[last_code][0]);
            arr.push_back(k);
            for (unsigned char el: arr[nc]) {
                wr.set_byte(el-1);
            }
            last_code = nc;
        } else {
            for (unsigned char el: arr[nc]) {
                wr.set_byte(el-1);
            }
            std::vector<unsigned char> k = arr[last_code];
            k.push_back(arr[nc][0]);
            arr.push_back(k);
            last_code = nc;
        }
    }
}
