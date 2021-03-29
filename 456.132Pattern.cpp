//
// Created by Kenway on 3/24/2021.
//
#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

//class Solution {
//public:
//    bool find132pattern(vector<int>& nums) {
//        int n = nums.size();
//        if (n < 3) return false;
//
//        int leftMin = nums[0];
//        multiset<int> set;
//        for (int i = 2; i < n; ++i) {
//            set.emplace(nums[i]);
//        }
//
//        for (int i = 1; i < n; ++i) {
//            if (leftMin < nums[i]) {
//                auto no3 = set.upper_bound(leftMin);
//                if (no3 != set.end() && *no3 < nums[i]) return true;
//            }
//            leftMin = min(leftMin, nums[i]);
//            set.erase(set.find(nums[i + 1]));
//        }
//
//        return false;
//    }
//};

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size(), max_k = INT_MIN;
        stack<int> stk;

        if (n < 3) return false;

        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] < max_k) return true;
            while (!stk.empty() && stk.top() < nums[i]) {
                max_k = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }

        return false;
    }
};