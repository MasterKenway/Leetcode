#include <iostream>

class Solution {
public:
    int reverse(int x) {
        int array[32];
        int i = 0;
        int result = 0;

        while (x != 0) {
            array[i] = x % 10;
            x = x / 10;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && array[i] > 7)) {
                return 0;
            }
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && array[i] < -8)) {
                return 0;
            }
            result = result * 10 + array[i];
            i++;
        }

        return result;
    }
};
//
//int main() {
//    Solution solution;
//    solution.reverse(-2147483648);
//}