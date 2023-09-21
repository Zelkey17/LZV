//
// Created by ash on 21.09.23.
//

#include "int_code.h"

int len(unsigned long long int a) {
    int cnt = 0;
    for (; a > 0; a /= 2, cnt++);
    return cnt;
}

std::vector<bool> get_bit(unsigned long long int a) {
    std::vector<bool> arr;
    for (; a > 0; a /= 2) {
        arr.push_back(a & 1);
    }
    std::reverse(arr.begin(), arr.end());
    return arr;
}

std::vector<bool> gamma_elias(unsigned long long int a) {
    std::vector<bool> ans;
    auto arr = get_bit(a);
    for (int i = 1; i < arr.size(); i++) {
        ans.push_back(false);

    }
    for (bool el: arr)ans.push_back(el);
    return ans;
}

std::vector<bool> delta_elias(unsigned long long int a) {
    auto arr = get_bit(a);
    auto ans = gamma_elias(arr.size());
    for (bool el: arr | std::views::drop(1)) {
        ans.push_back(el);
    }
    return ans;
}

unsigned long long from_gamma_elias(Reader &rd) {
    int cnt = 0;
    bool fl = false;
    while (!fl && rd.get_bit(fl))cnt++;
    if (!fl) {
        return 0;
    }
    unsigned long long ans = fl;
    for (int i = 1; i < cnt; i++) {
        ans <<= 1;
        bool t;
        if (!rd.get_bit(t))return 0;
        ans += t;
    }
    return ans;
}

unsigned long long from_delta_elias(Reader &rd) {
    unsigned int length = from_gamma_elias(rd);
    if (length == 0)return 0;
    unsigned long long ans = 1;
    for (int i = 1; i < length; i++) {
        ans <<= 1;
        bool fl;
        if (!rd.get_bit(fl))return 0;
        ans += fl;
    }
    return ans;
}
