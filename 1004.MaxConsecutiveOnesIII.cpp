//
// Created by Kenway on 2/19/2021.
//
#include <vector>

class Solution {
public:
    int longestOnes(std::vector<int> &A, int K) {
        int left = 0, right = 0, n = A.size(), res = 0, counter = 0;

        while (right < n) {
            if (A[right] == 0) counter++;

            while (counter > K) {
                if (A[left] == 0) counter--;
                left++;
            }

            res = std::max(res, right - left + 1);

            right++;
        }

        return res;
    }
};