//
// Created by Kenway on 2/4/2021.
//
#include <vector>

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        double max = 0, curr = 0;
        for (int i = 0; i < nums.size(); ++i) {
            curr += (double) nums[i];
            if (i >= k - 1) {
                if (i > k - 1)
                    curr -= (double) nums[i - k];
                double tmp = (double) curr / k;
                max =  std::max(max, tmp);
            }
        }

        if (nums.size() == k)
            max = curr / k;

        return max;
    }
};