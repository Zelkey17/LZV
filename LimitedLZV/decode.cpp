//
// Created by ash on 21.09.23.
//

#include "decode.h"

void decode(Reader &rd, Writer &wr) {

    std::vector<std::vector<unsigned char>> arr(1);
    for (int i = 1; i <= 256; i++) {
        arr.push_back({(unsigned char) i});
    }
    unsigned long long last_code = get_n_bit_int(rd, 1 + (int) std::__lg(arr.size()));
    std::cout << last_code << " ";
    for (unsigned char el: arr[last_code]) {
        wr.set_byte((char) (el - 1));
    }
    unsigned long long nc;
    while ((nc = get_n_bit_int(rd, 1 + (int) std::__lg(arr.size())))) {
        if (nc == arr.size()) {
            std::vector<unsigned char> k = arr[last_code];
            k.push_back(arr[last_code][0]);
            arr.push_back(k);
            for (unsigned char el: arr[nc]) {
                wr.set_byte((char) (el - 1));
            }
            last_code = nc;
            //std::cout << last_code << " ";

        } else {
            for (unsigned char el: arr[nc]) {
                wr.set_byte((char) (el - 1));
            }
            std::vector<unsigned char> k = arr[last_code];
            k.push_back(arr[nc][0]);
            arr.push_back(k);

            last_code = nc;
            if (arr.size() == (1 << 16)) {
                arr.shrink_to_fit();
                decode(rd, wr);
                return;
            }
        }
    }

}

unsigned long long get_n_bit_int(Reader &rd, int n) {
    unsigned long long ans = 0;
    for (int i = 0; i < n; i++) {
        bool t;
        if (!rd.get_bit(t))return 0;
        ans <<= 1;
        ans += t;
    }
    return ans;
}
