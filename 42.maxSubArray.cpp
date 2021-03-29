//
// Created by Kenway on 2/8/2021.
//
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int> &nums) {
        int n = nums.size(), max = nums[0];
        std::vector<int> dp(n, 0);

        if (n == 1) return nums[0];

        dp[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            if (dp[i - 1] < 0)
                dp[i] = nums[i];
            else
                dp[i] = dp[i - 1] + nums[i];

            max = std::max(max, dp[i]);
        }

        return max;
    }
};