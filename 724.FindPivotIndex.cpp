//
// Created by Kenway on 1/28/2021.
//
#include <vector>

class Solution {
public:
    int pivotIndex(std::vector<int> &nums) {
        int n = nums.size(), i = 0, j = n - 1;
        unsigned int left = 0, right = 0;
        left += nums[i++];
        while (i < j) {
            if (left == right) {
                return i;
            } else if (left < right) {
                left += nums[i++];
            } else if (left > right) {
                right += nums[j++];
            }
        }
        return -1;
    }
};