//
// Created by Kenway on 1/28/2021.
//

class Solution {
public:
    int getSum(int a, int b) {
        int res = a ^ b, carry = (unsigned int) (a & b) << 1;
        while (carry) {
            int temp = res;
            res ^= carry;
            carry =(unsigned int) (temp & carry) << 1;
        }
        return res;
    }
};