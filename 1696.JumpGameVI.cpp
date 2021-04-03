//
// Created by Kenway on 3/30/2021.
//

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//class Solution {
//public:
//    int maxResult(vector<int>& nums, int k) {
//        int size = nums.size();
//        if (size < 2) return nums[0];
//        vector<int> dp(size, INT_MIN);
//        dp[0] = nums[0];
//        for (int i = 1; i < size; ++i) {
//            int kk = 1;
//            while (i - kk >= 0 && kk <= k) {
//                dp[i] = max(dp[i - kk], dp[i]);
//                kk++;
//            }
//            dp[i] += nums[i];
//        }
//        return dp[size - 1];
//    }
//};
//
//class Solution {
//public:
//    int maxResult(vector<int>& nums, int k) {
//        int size = nums.size();
//        priority_queue<pair<int, int>> queue;
//        queue.emplace(make_pair(nums[0], 0));
//        int res;
//        for (int i = 1; i < size; ++i) {
//            while (i - queue.top().second > k) {
//                queue.pop();
//            }
//            res = nums[i] + queue.top().first;
//            queue.emplace(res, i);
//        }
//
//        return res;
//    }
//};

class Solution {
public:
    int maxResult(vector<int> &nums, int k) {
        int size = nums.size();
        deque<pair<int, int>> queue;
        queue.emplace_back(nums[0], 0);
        int res = nums[0];
        for (int i = 1; i < size; ++i) {
            while (i - queue.front().second > k) {
                queue.pop_front();
            }

            res = queue.front().first + nums[i];

            while (!queue.empty() && queue.back().first <= res) queue.pop_back();
            queue.emplace_back(res, i);
        }

        return res;
    }
};


int main() {
    vector<int> array = {100,-1,-100,-1,100};
    int k = 2;
    Solution solution;
    solution.maxResult(array, k);
}