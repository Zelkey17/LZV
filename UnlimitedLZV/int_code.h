//
// Created by ash on 21.09.23.
//
#ifndef LZV_UNLIMITED_INT_CODE_H
#define LZV_UNLIMITED_INT_CODE_H

#include <vector>
#include <ranges>
#include "Reader.h"


int len(unsigned long long a);

std::vector<bool> get_bit(unsigned long long a);

std::vector<bool> gamma_elias(unsigned long long a);

std::vector<bool> delta_elias(unsigned long long a);

unsigned long long from_gamma_elias(Reader &rd);

unsigned long long from_delta_elias(Reader &rd);

#endif //LZV_UNLIMITED_INT_CODE_H