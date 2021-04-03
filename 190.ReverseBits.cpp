//
// Created by Kenway on 3/29/2021.
//
#include <iostream>

//class Solution {
//public:
//    uint32_t reverseBits(uint32_t n) {
//        uint32_t  res = 0;
//        int i = 32;
//        while (i) {
//            res = (res << 1 ) + (n & 1);
//            n >>= 1;
//            i--;
//        }
//        return res;
//    }
//};

class Solution {
public:
    const uint32_t M1 = 0x55555555; // 01010101010101010101010101010101
    const uint32_t M2 = 0x33333333; // 00110011001100110011001100110011
    const uint32_t M4 = 0x0f0f0f0f; // 00001111000011110000111100001111
    const uint32_t M8 = 0x00ff00ff; // 00000000111111110000000011111111

    uint32_t reverseBits(uint32_t n) {
        n = n >> 1 & M1 | (n & M1) << 1;
        n = n >> 2 & M2 | (n & M2) << 2;
        n = n >> 4 & M4 | (n & M4) << 4;
        n = n >> 8 & M8 | (n & M8) << 8;
        return n >> 16 | n << 16;
    }
};