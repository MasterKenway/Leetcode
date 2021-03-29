//
// Created by Kenway on 2/7/2021.
//
#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     * 3 4 1 2
     *
     * 4 2 3
     *
     * -1 4 2 3
     *
     */

    bool checkPossibility(std::vector<int> &nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] > nums[i]) {
                int tmp = nums[i - 1];
                nums[i - 1] = nums[i];
                if (std::is_sorted(nums.begin(), nums.end()))
                    return true;

                nums[i - 1] = tmp;
                nums[i] = tmp;
                return std::is_sorted(nums.begin(), nums.end());
            }
        }

        return true;

    }
};