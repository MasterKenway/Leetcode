//
// Created by Kenway on 2/13/2021.
//
#include <vector>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            nums[(nums[i] - 1) % n] += n;

        }

        std::vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= n) res.push_back(i + 1);
        }

        return res;
    }
};