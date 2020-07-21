//
// Created by Kenway on 7/19/2020.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0, right = height.size() - 1, max = 0, lowOne = -1;
        while (left != right) {
            lowOne = height[left] <= height[right] ? left : right;

            if (max < (height[lowOne] * (right - left))) {
                max = height[lowOne] * (right - left);
            }

            if (height[left] <= height[right])
                left++;
            else
                right--;
        }

        return max;
    }
};

//int main() {
//    Solution solution;
//    std::vector<int> height = {1,8,6,2,5,4,8,3,7};
//    std::cout << solution.maxArea(height) << std::endl;
//
//}