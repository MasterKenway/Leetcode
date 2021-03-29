//
// Created by Kenway on 3/4/2021.
//
#include <vector>
#include <string>

class Solution {
public:
    int translateNum(int num) {
        std::string str = std::to_string(num);
        int size = str.size();
        std::vector<int> dp(size + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= size; ++i) {
            std::string pre = str.substr(i - 2, 2);
            int number = std::stoi(pre);
            if (number >= 10 && number <= 25) {
                dp[i] = dp[i - 1] + dp[i - 2];
            } else {
                dp[i] = dp[i - 1];
            }
        }

        return dp[size];
    }
};