//
// Created by Kenway on 7/27/2020.
//

#include <iostream>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        int i = 0;

        if (strs.empty())
            return "";

        while (1) {
            for (int j = 0; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[0][i] != strs[j][i])
                    return strs[0].substr(0, i);
            }
            i++;
        }
    }
};

//int main() {
//    Solution solution;
//    std::vector<std::string> strs = {};
//    std::cout << solution.longestCommonPrefix(strs) << std::endl;
//}