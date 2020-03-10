#include <iostream>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int max = 1, left, right, maxLeft = 0, maxRight = 0;

        if (s.empty()) return "";

        for (int i = 1; i < s.size(); ++i) {

            left = i;
            right = i;
            while (left >= 0 && right <= s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            if (max < (right - left - 1)) {
                max = right - left - 1;
                maxLeft = left + 1;
                maxRight = right - 1;
            }

            left = i - 1;
            right = i;
            while (left >= 0 && right <= s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            if (max < (right - left - 1)) {
                max = right - left - 1;
                maxLeft = left + 1;
                maxRight = right - 1;
            }
        }

        return s.substr(maxLeft, max);
    }
};

/*
int main() {
    std::string s = "abbc";
    //std::string s = "adadc";
    //std::string s = "a";
    //std::string s = "";
    //std::string s = "bb";
    //std::string s = "adbce";
    //std::string s = "ccc";

    Solution solution;
    std::string target = solution.longestPalindrome(s);

    std::cout << "\"" << target << "\"" << std::endl;

}*/
