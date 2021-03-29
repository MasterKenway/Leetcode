//
// Created by Kenway on 1/26/2021.
//
#include <vector>
#include <map>

class Solution {
public:
    int numEquivDominoPairs(std::vector<std::vector<int>> &dominoes) {
        int length = dominoes.size();
        std::map<std::vector<int>, int> map;
        auto process = [&] (std::vector<int> array) -> vector<int> {
            return {std::max(array[0], array[1]), std::min(array[0], array[1])};
        };

        for (int i = 0; i < length; ++i) {
            auto key = process(dominoes[i]);
            map[key]++;
        }

        // A(3, 2) 全排列
        int counter = 0;
        for (auto &element : map) {
            counter += element.second * (element.second - 1);
        }

        return counter / 2;
    }
};
