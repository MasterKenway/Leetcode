//
// Created by Kenway on 7/28/2020.
//
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        std::vector<std::vector<int>> res = {};
        std::sort(nums.begin(), nums.end());

        if (nums.size() < 3)
            return {};

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            int k = nums.size() - 1;

            for (int j = i+1; j < nums.size() - 1; ++j) {
                if (j != i+1 && nums[j] == nums[j - 1])
                    continue;

                while (nums[i] + nums[j] + nums[k] > 0 && j < k)
                    k--;

                if (j == k)
                    break;

                if (nums[i] + nums[j] + nums[k] == 0)
                    res.push_back({nums[i], nums[j], nums[k]});
            }
        }

        return res;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {0,1,1};
    solution.threeSum(nums);
}