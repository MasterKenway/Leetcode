//
// Created by Kenway on 2/16/2021.
//
#include <vector>
#include <algorithm>

class Solution {
public:
    int arrayPairSum(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, right = n;

        int res = 0;
        for (int i = 0; i < n; i+=2) {
            res += nums[i];
        }

        return res;
    }
};