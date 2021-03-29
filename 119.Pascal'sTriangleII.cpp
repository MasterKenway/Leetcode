//
// Created by Kenway on 2/12/2021.
//
#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<std::vector<int>> array(rowIndex, std::vector<int>(rowIndex, 1));
        array[0][0] = 1;
        array[0][1] = 1;
        array[1][1] = 1;
        for (int i = 2; i < rowIndex; ++i) {
            for (int j = 1; j < i; ++j) {
                array[i][j] = array[i - 1][j - 1] + array[i - 1][j];
            }
        }

        return array[rowIndex - 1];
    }
};