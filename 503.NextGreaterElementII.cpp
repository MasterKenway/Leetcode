//
// Created by Kenway on 3/6/2021.
//
#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        std::stack<int> stack;
        int size = nums.size();
        std::vector<int> res(size, -1);
        for (int i = 0; i < size * 2 - 1; ++i) {
            while (!stack.empty() && nums[stack.top()] < nums[i % size]) {
                res[stack.top()] = nums[i % size];
                stack.pop();
            }
            stack.push(i % size);
        }
        return res;
    }

};