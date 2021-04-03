//
// Created by Kenway on 3/31/2021.
//

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int> &nums, vector<int> &path, int index, bool pre) {
        if (index == nums.size()) {
            res.push_back(path);
            return;
        }

        dfs(nums, path, index + 1, false);
        if (!pre && index > 0 && nums[index - 1] == nums[index]) {
            return;
        }

        path.push_back(nums[index]);
        dfs(nums, path, index + 1, true);
        path.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        dfs(nums, path, 0);
        return res;
    }
};

int main() {
    vector<int> nums = {1,2,2};
    Solution solution;
    solution.subsetsWithDup(nums);

    return 0;
}