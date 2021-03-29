//
// Created by Kenway on 2/10/2021.
//
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        std::vector<int> array;
        array.push_back(0);
        for (int i = 1; i < prices.size(); ++i) {
            array.push_back(prices[i] - prices[i - 1]);
        }

        std::vector<int> dp(prices.size(), 0);
        int res = dp[0];
        for (int i = 1; i < array.size(); ++i) {
            if (dp[i - 1] < 0) dp[i] = array[i];
            else dp[i] += dp[i - 1];

            res = std::max(dp[i], res);
        }

        return res;
    }
};