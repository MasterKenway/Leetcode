//
// Created by Kenway on 7/27/2020.
//

#include <iostream>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        return i == s.length();
    }
};

//int main() {
//    Solution solution;
//    std::cout << solution.isSubsequence("abc", "ahbgdc") << std::endl;
//    std::cout << solution.isSubsequence("axc", "ahbgdc") << std::endl;
//}
