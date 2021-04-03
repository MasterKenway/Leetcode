//
// Created by Kenway on 3/30/2021.
//
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int height = matrix.size(), width = matrix[0].size(), left = 0, right = height * width - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            int x = mid / width, y = mid % width;
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] < target) {
                left = mid + 1;
            } else {
                // matrix[x][y] > target
                right = mid;
            }
        }
        return false;
    }
};