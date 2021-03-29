//
// Created by Kenway on 2/10/2021.
//
#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int distance = nums[0] + 1, n = nums.size();
        if (distance > n) return true;

        for (int i = 1; i < distance; ++i) {
            if (i + nums[i] > distance) distance = i + nums[i];
            if (distance > n) return true;
        }

        return false;
    }
};