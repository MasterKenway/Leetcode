class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        if (!nums.size()) return 0;

        int max = 1;
        int length = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                max = max > ++length ? max : length;
            } else {
                length = 0;
            }
        }
        return max;
    }
};