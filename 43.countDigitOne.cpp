//
// Created by Kenway on 2/8/2021.
//
#include <vector>

class Solution {
public:
    int countDigitOne(int n) {
        int total = 0;

        for (int i = 1; i <= n; ++i) {
            total += countOne(i);
        }

        return total;
    }

    int countOne(int num) {
        int counter = 0, tmp = 10;
        while (num) {
            if (num % tmp == 1)
                counter++;
            num = num / 10;
        }

        return counter;
    }
};