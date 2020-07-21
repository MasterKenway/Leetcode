//
// Created by Kenway on 7/19/2020.
//
#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 )
            return false;

        int div = 1;
        while (x / div >= 10)
            div *= 10;

        int left, right;
        while (x > 0) {
            left = x / div;
            right = x % 10;
            if (left != right)
                return false;
            x = x % div;
            x = x / 10;
            div = div / 100;
        }

        return true;
    }
};

//int main() {
//    Solution solution;
//    std::cout << solution.isPalindrome(1221) << std::endl;
//}