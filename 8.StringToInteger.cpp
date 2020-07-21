//
// Created by Kenway on 7/17/2020.
//

#include <iostream>

class Solution {
public:
    int myAtoi(std::string str) {
        int length = str.length();
        int result = 0;

        int i = 0;
        while (i < length && str[i] == ' ') {i++;}

        int j = i;
        i = 0;

        int flag = 1;
        if (str[j] == '-') {
            flag = -1;
            j++;
        } else if (str[j] == '+') {
            j++;
        }

        printf("%d ", flag);

        while (j < length && str[j] >= '0' && str[j] <= '9') {
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && flag * (str[j] - '0') > 7)) {
                return INT_MAX;
            }
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && flag * (str[j] - '0') < -8)) {
                return INT_MIN;
            }
            result = result * 10 + flag * (str[j] - '0');
            j++;
        }

        return result;
    }

};

//int main() {
//    Solution solution;
//    std::cout << solution.myAtoi("-2147483649") << std::endl;
//}