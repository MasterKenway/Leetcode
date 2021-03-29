//
// Created by Kenway on 3/11/2021.
//
#include <string>
#include <stack>

class Solution {
public:
    int calculate(std::string s) {
        int pos = s.find(" ");
        while (pos != -1) {
            s.replace(pos, 1, "");
            pos = s.find(" ");
        }

        std::stack<int> nums;
        std::stack<char> ops;
        nums.push(0);

        for (int i = 0; i < s.length(); ++i) {
            if (isdigit(s[i])) {
                int j = i, num = 0;
                while (j < s.length() && isdigit(s[j])) {
                    num = num * 10 + (s[j] - '0');
                    j++;
                }
                nums.push(num);
                i = j - 1;

                if (!ops.empty() && (ops.top() == '/' || ops.top() == '*') && nums.size() >= 2) {
                    int b = nums.top();
                    nums.pop();
                    int a = nums.top();
                    nums.pop();

                    if (ops.top() == '/') {
                        nums.push(a / b);
                    } else {
                        nums.push(a * b);
                    }
                    ops.pop();
                }
            } else if (s[i] == '+' || s[i] == '-') {
                if (!ops.empty() && ops.top() == '+' && nums.size() >= 2) {
                    int b = nums.top();
                    nums.pop();
                    int a = nums.top();
                    nums.pop();

                    nums.push(a + b);
                    ops.pop();

                } else if (!ops.empty() && ops.top() == '-' && nums.size() >= 2) {
                    int b = nums.top();
                    nums.pop();
                    int a = nums.top();
                    nums.pop();

                    nums.push(a - b);
                    ops.pop();

                }

                ops.push(s[i]);
            } else if (s[i] == '/' || s[i] == '*') {
                ops.push(s[i]);
            }
        }

        while (!ops.empty() && nums.size() >= 2) {
            int b = nums.top();
            nums.pop();
            int a = nums.top();
            nums.pop();

            if (ops.top() == '+') {
                nums.push(a + b);
            } else if (ops.top() == '-') {
                nums.push(a - b);
            }
            ops.pop();
        }

        return nums.top();
    }
};


int main() {
    Solution solution;
    solution.calculate("3+2*2");
}