//
// Created by Kenway on 2/6/2021.
//
#include <vector>
#include <math.h>

class Solution {
public:
    int maxAbsoluteSum(std::vector<int> &nums) {
        int n = nums.size(), max = 0;
        std::vector<int> dp(n, 0);
        std::vector<int> dp2(n, 0);
        if (n == 1) return std::abs(nums[0]);

        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (dp[i - 1] < 0)
                dp[i] = nums[i];
            else
                dp[i] = dp[i - 1] + nums[i];
        }

        dp2[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (dp2[i - 1] >= 0)
                dp2[i] = nums[i];
            else
                dp2[i] = dp2[i - 1] + nums[i];
        }

        for (auto item : dp) {
            if (std::abs(item) > max)
                max = std::abs(item);
        }

        for (auto item : dp2) {
            if (std::abs(item) > max)
                max = std::abs(item);
        }

        return max;
    }
};