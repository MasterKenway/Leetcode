//
// Created by Kenway on 3/6/2021.
//
#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2) {
        std::stack<int> stack;
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums2.size(); ++i) {
            if (stack.empty()) {
                stack.push(nums2[i]);
            } else {
                int top = stack.top();
                while (!stack.empty() && top < nums2[i]) {
                    map[top] = nums2[i];
                    stack.pop();
                    if (!stack.empty()) {
                        top = stack.top();
                    }
                }
                stack.push(nums2[i]);
            }
        }

        while (!stack.empty()) {
            int top = stack.top();
            map[top] = -1;
            stack.pop();
        }

        std::vector<int> res;
        for (int i = 0; i < nums1.size(); ++i) {
            res.push_back(map[nums1[i]]);
        }

        return res;
    }
};

int main() {
    Solution solution;

    std::vector<int> nums = {4,1,2};
    std::vector<int> nums2 = {1,3,4,2};
    solution.nextGreaterElement(nums, nums2);
}