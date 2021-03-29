//
// Created by Kenway on 3/4/2021.
//
#include <vector>
#include <algorithm>

//class Solution {
//public:
//    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
//        if (envelopes.empty()) {
//            return 0;
//        }
//
//        int size = envelopes.size();
//
//        std::sort(envelopes.begin(), envelopes.end(), [](const auto& env1, const auto& env2) {
//            // 高度降序是为了避免同一宽度的信封被多次选中
//            return env1[0] < env2[0] || (env1[0] == env2[0] && env1[1] > env2[1]);
//        });
//
//        std::vector<int> dp(size, 0);
//        for (int i = 0; i < size; ++i) {
//            for (int j = 0; j < i; ++j) {
//                if (envelopes[j][1] < envelopes[i][1]) {
//                    dp[i] = std::max(dp[i], dp[j] + 1);
//                }
//            }
//        }
//
//        return *std::max_element(dp.begin(), dp.end());
//    }
//};


class Solution {
public:
    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        if (envelopes.empty()) {
            return 0;
        }

        int size = envelopes.size();

        std::sort(envelopes.begin(), envelopes.end(), [](const auto& env1, const auto& env2) {
            // 高度降序是为了避免同一宽度的信封被多次选中
            return env1[0] < env2[0] || (env1[0] == env2[0] && env1[1] > env2[1]);
        });

        std::vector<int> array = {envelopes[0][1]};
        for (int i = 1; i < size; ++i) {
            if (envelopes[i][1] > array.back()) {
                array.push_back(envelopes[i][1]);
            } else {
                auto p = std::lower_bound(array.begin(), array.end(), envelopes[i][1]);
                *p = envelopes[i][1];
            }
        }

        return array.size();
    }
};