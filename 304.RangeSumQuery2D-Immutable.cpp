//
// Created by Kenway on 3/20/2021.
//
#include <vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> sums;

    NumMatrix(vector<vector<int>> &matrix) {
        int height = matrix.size(), width = matrix[0].size();
        sums.assign(height, vector<int>(width, 0));
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                sums[i][j + 1] = matrix[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = 0;
        for (int i = row1; i < row2; ++i) {
            total += sums[i][col2 + 1] - sums[i][col1];
        }
        return total;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */