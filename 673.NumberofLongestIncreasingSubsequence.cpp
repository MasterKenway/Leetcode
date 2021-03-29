//
// Created by MasterKenway <zk@ikenway.net> on 1/24/2021.
//
#include <vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int> &nums) {
        int size = nums.size();
        std::vector<int> dp(size, 1);
        dp[0] = 1;
        for (int i = 1; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i])
                    dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        return dp[size - 1];
    }
};