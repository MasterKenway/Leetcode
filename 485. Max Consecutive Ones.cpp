//
// Created by Kenway on 2/15/2021.
//
#include <vector>

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int> &nums) {
        int size = nums.size(), left = 0, right = 0, max = 0;
        while (right < size && left < size) {
            if (nums[right] == 1) {
                max = std::max(right - left + 1, max);
            } else {
                left = right + 1;
            }
            right++;
        }
        return max;
    }
};