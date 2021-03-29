//
// Created by Kenway on 2/10/2021.
//
#include <vector>

class Solution {
public:
    int rob(std::vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        std::vector<int> dp(n, 0);

        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[n - 1];
    }
};