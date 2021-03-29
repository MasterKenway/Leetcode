//
// Created by Kenway on 3/16/2021.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, -1));
        vector<vector<int>> direction = {{0,  1},
                                         {1,  0},
                                         {0,  -1},
                                         {-1, 0}};
        int total = n * n, direct = 0, x = 0, y = 0;
        for (int i = 0; i < total; ++i) {
            res[x][y] = i + 1;

            if (x + direction[direct][0] < 0 || x + direction[direct][0] >= n
                || y + direction[direct][1] < 0 || y + direction[direct][1] >= n
                || res[x+ direction[direct][0]][y+ direction[direct][1]] >= 0) {
                direct = (direct + 1) % 4;
            }

            x += direction[direct][0];
            y += direction[direct][1];
        }

        return res;
    }
};