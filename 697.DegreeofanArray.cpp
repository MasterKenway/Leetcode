//
// Created by Kenway on 2/20/2021.
//
#include <vector>
#include <unordered_map>

class Solution {
public:
    int findShortestSubArray(std::vector<int>& nums) {
        std::unordered_map<int, std::vector<int>> map;
        int res = 0, counter = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (map.count(nums[i])) {
                map[nums[i]][0]++;
                map[nums[i]][2] = i;
            } else {
                map[nums[i]] = {1, i, i};
            }
        }

        for (auto& [_, vec] : map) {
            if (counter < vec[0]) {
                counter = vec[0];
                res = vec[2] - vec[1] + 1;
            } else if (counter == vec[0]) {
                res = std::min(vec[2] - vec[1] + 1, res);
            }
        }

        return res;
    }
};