#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /*vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>array;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    array.push_back(i);
                    array.push_back(j);
                    break;
                }
            }
            if (!array.empty())
                break;
        }
        return array;
    }*/

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>map;
        vector<int>result;
        vector<int>::iterator it = nums.begin();
        for (int i = 0; i < nums.size(); ++i) {
            map[*it] = i;
            it++;
        }
        it = nums.begin();
        for (int j = 0; j < nums.size(); ++j) {
            int tmp = target - *it;
            if (map.find(tmp) != map.end() && map[tmp] != j){
                result.push_back(j);
                result.push_back(map[tmp]);
                break;
            }
            it++;
        }
        return result;
    }
};

/*int main() {
    Solution solution;

    vector<int>nums = {3,2,4};

    vector<int>array = solution.twoSum(nums, 6);

    vector<int>::iterator it = array.begin();

    while (it != array.end()) {
        cout << *it << endl;
        it++;
    }
}*/
