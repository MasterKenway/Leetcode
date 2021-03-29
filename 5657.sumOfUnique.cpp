//
// Created by Kenway on 2/6/2021.
//
#include <vector>
#include <unordered_map>

class Solution {
public:
    int sumOfUnique(std::vector<int>& nums) {
        std::unordered_map<int, int> map;
        for (auto num : nums) {
            map[num]++;
        }

        int total = 0;
        for (auto item : map) {
            if (item.second == 1)
                total += item.first;
        }

        return total;
    }
};