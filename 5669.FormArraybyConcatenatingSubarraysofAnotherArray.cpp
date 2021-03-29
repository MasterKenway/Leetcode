//
// Created by Kenway on 2/20/2021.
//
#include <vector>

class Solution {
public:
    bool canChoose(std::vector<std::vector<int>>& groups, std::vector<int>& nums) {
        int p = 0, q = 0, n = nums.size(), i = 0;
        while (p < n) {

            while (groups[i][q] == nums[p]) {
                q++;
                p++;
                if (q == groups[i].size()) {
                    i++;
                    if (i == groups.size()) break;
                    q = 0;
                }
            }

            p++;
        }

        if (i == groups.size()) {
            if (groups.size() == 1 && q == groups[i].size()) {
                return true;
            }

            if (i - 1 >= 0 && q == groups[i - 1].size()) {
                return true;
            }
            return false;
        }

        return false;
    }
};

