//
// Created by Kenway on 2/17/2021.
//
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>> &nums, int r, int c) {
        int row = nums.size(), col = nums[0].size();
        if (row * col != r * c) return nums;

        std::vector<std::vector<int>> res(r, std::vector<int>(c, 0));
        std::vector<int> array;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                array.push_back(nums[i][j]);
            }
        }

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res[i][j] = array[i * col + j];
            }
        }

        return res;
    }
};
