#include <iostream>
#include <string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        std::string target = "";

        if (numRows == 1) return s;

        int cyclelen = numRows + numRows - 2;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j + i < s.size(); j += cyclelen) {
                target += s[i + j];
                if (i != 0 && i != numRows - 1 && j + cyclelen - i < s.size())
                    target += s[j + cyclelen - i];
            }
        }
        return target;
    }
};

int main() {
    std::string s = "LEETCODEISHIRING";
    int numRows = 3;


    Solution solution;
    std::string target = solution.convert(s, numRows);

    std::cout << target << std::endl;
}