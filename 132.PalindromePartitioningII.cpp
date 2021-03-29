//
// Created by Kenway on 3/8/2021.
//
#include <string>
#include <vector>


class Solution {
public:
    std::vector<std::vector<bool>> dp;

    int minCut(std::string s) {
        dp.assign(s.length(), std::vector<bool>(s.length(), true));

        for (int i = s.length(); i >= 0; --i) {
            for (int j = i + 1; j < s.length(); ++j) {
                dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1]);
            }
        }

        std::vector<int> dp2(s.length() + 1, INT_MAX);
        for (int i = 0; i < s.length(); ++i) {
            if (dp[0][i]) {
                dp[i] = 0;
            } else {
                for (int j = 0; j < i; ++j) {
                    if (dp[j][i]) {
                        dp2[i] = std::min(dp2[i], dp2[j] + 1);
                    }
                }
            }
        }

        return dp2[s.length() - 1];
    }
};