//
// Created by Kenway on 3/30/2021.
//

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        if (nums.empty()) return {};

        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(size, 1);
        vector<int> path(size, -1);
        int maxLen = 0;
        int maxIndex = -1;

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    path[i] = j;
                }
            }

            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIndex = i;
            }
        }

        vector<int> res;
        int i = maxIndex;
        while (i != -1) {
            res.push_back(nums[i]);
            i = path[i];
        }
        reverse(res.begin(), res.end());

        return res;
    }
};