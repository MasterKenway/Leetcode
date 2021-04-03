//
// Created by Kenway on 4/3/2021.
//

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int length1 = text1.length(), length2 = text2.length();
        vector<vector<int>> dp(length2 + 1, vector<int>(length1 + 1, 0));

        for (int i = 1; i <= length2; ++i) {
            for (int j = 1; j <= length1 ; ++j) {
                if (text1[j - 1] == text2[i - 1]) {
                    dp[i][j] = dp[i][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[length2][length1];
    }
};

int main() {
    string str1 = "bsbininm", str2 = "jmjkbkjkv";
    Solution solution;
    solution.longestCommonSubsequence(str1, str2);
}