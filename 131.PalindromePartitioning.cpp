//
// Created by Kenway on 3/7/2021.
//
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::vector<bool>> dp;
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> ans;

    void dfs(std::string &s, int index) {
        if (index == s.length()) {
            res.push_back(ans);
        }

        for (int i = index; i < s.length(); ++i) {
            if (dp[index][i]) {
                ans.push_back(s.substr(index, i - index + 1));
                dfs(s, i + 1);
                ans.pop_back();
            }
        }
    }

    std::vector<std::vector<std::string>> partition(std::string s) {
        dp.assign(s.length(), std::vector<bool>(s.length(), true));

        for (int i = s.length(); i >= 0; --i) {
            for (int j = i + 1; j < s.length(); ++j) {
                dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1]);
            }
        }

        dfs(s, 0);

        return res;
    }
};