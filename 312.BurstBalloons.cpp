//
// Created by Kenway on 7/19/2020.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> rec;
    std::vector<int> val;

    int maxCoins(std::vector<int>& nums) {
        val.resize(nums.size() + 2, 1);
        for (int i = 1; i <= nums.size(); ++i)
            val[i] = nums[i - 1];
        rec.resize(nums.size() + 2, std::vector<int>(nums.size() + 2, -1) );
        return solve(0, (nums.size() + 1));
    }

    int solve(int left, int right) {
        if (left >= right - 1)
            return 0;

        if (rec[left][right] != -1)
            return rec[left][right];

        for (int i = left + 1; i < right; ++i) {
            int sum = val[left] * val[i] * val[right];
            sum += solve(left, i) + solve(i, right);
            rec[left][right] = std::max(rec[left][right], sum);
        }

        return rec[left][right];
    }
};
//
//int main() {
//    Solution solution;
//    std::vector<int> a = {3, 1, 5, 8};
//    std::cout << solution.maxCoins(a) << std::endl;
//}