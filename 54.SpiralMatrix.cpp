//
// Created by Kenway on 3/15/2021.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int height = matrix.size(), width = matrix[0].size(), x = 0, y = 0, i = 0, total = height * width, direct = 0;
        vector<vector<int>> direction = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<int> res;

        while (i < total) {
            res.push_back(matrix[x][y]);
            matrix[x][y] += 201;
            if (x + direction[direct][0] < 0 || x + direction[direct][0] >= height
            || y + direction[direct][1] < 0 || y + direction[direct][1] >= width
            || matrix[x+ direction[direct][0]][y+ direction[direct][1]] > 100) {
                direct = (direct + 1) % 4;
            }
            x += direction[direct][0];
            y += direction[direct][1];

            i++;
        }

        return res;
    }
};

int main() {
    vector<vector<int>> array = {{1,2,3}, {4,5,6}, {7,8,9}};

    Solution solution;
    solution.spiralOrder(array);
}