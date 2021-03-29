//
// Created by Kenway on 3/20/2021.
//
#include <vector>

using namespace std;

//class Solution {
//public:
//    vector<int> countBits(int num) {
//        vector<int> res;
//        for (int i = 0; i <= num; ++i) {
//            int div = 1, counter = 0;
//            while (i / div) {
//                if (i & div) counter++;
//                div <<= 1;
//            }
//            res.push_back(counter);
//        }
//        return res;
//    }
//};



class Solution {
public:
    vector<int> mem;

    vector<int> countBits(int num) {
        mem.assign(num + 1, -1);
        for (int i = 0; i <= num; ++i) {
            mem[i] = count(i);
        }
        return mem;
    }

    int count(int num) {
        if (num == 0) return 0;
        if (mem[num] != -1) return mem[num];
        if (num % 2) {
            mem[num] = count(num - 1) + 1;
            return mem[num];
        }
        mem[num] = num / 2;
        return mem[num];
    }
};