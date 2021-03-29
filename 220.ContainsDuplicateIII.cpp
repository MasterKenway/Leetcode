//
// Created by Kenway on 1/28/2021.
//
#include <set>
#include <vector>
#include <math.h>

class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) {
        std::multiset<int> treeSet;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            auto item = treeSet.lower_bound(nums[i] - t);
            if (item != treeSet.end() && *item <= nums[i] + t)
                return true;

            treeSet.insert(nums[i]);
            if (treeSet.size() > k)
                treeSet.erase(nums[i - k]);
        }
        return false;
    }
};




//#include <set>
//#include <vector>
//#include <math.h>
//
//class Solution {
//public:
//    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) {
//        std::multiset<int> treeSet;
//        int n = nums.size();
//        for (int i = 0; i < n; ++i) {
//            auto item = treeSet.lower_bound(nums[i] - t);
//            if (item != treeSet.end() && *item <= nums[i] + t)
//                return true;
//
//            treeSet.insert(nums[i]);
//            if (treeSet.size() > k)
//                treeSet.erase(nums[i - k ]);
//        }
//        return false;
//    }
//};
//
