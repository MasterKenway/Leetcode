//
// Created by Kenway on 3/10/2021.
//
#include <string>
#include <stack>
#include <iostream>

class Solution {
public:
    int calculate(std::string s) {
        int pos = s.find(" ");
        while (pos != -1) {
            s.replace(pos, 1, "");
            pos = s.find(" ");
        }

        pos = s.find("(-");
        while(pos != -1){
            s.replace(pos, 2, "(0-");
            pos = s.find("(-");
        }

        std::stack<char> op;
        std::stack<int> nums;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                op.push(s[i]);
            } else if (s[i] == ')') {
                if (!op.empty() && op.top() != '(' && nums.size() >= 2) {
                    int b = nums.top();
                    nums.pop();
                    int a = nums.top();
                    nums.pop();

                    if (op.top() == '+') {
                        nums.push(a + b);
                    } else {
                        nums.push(a - b);
                    }

                    op.pop();
                }
                op.pop();
            } else {

                if (std::isdigit(s[i])) {
                    int j = i;
                    int num = 0;
                    while (j < s.length() && std::isdigit(s[j])) {
                        num = num * 10 + (s[j] - '0');
                        j++;
                    }
                    i = j - 1;

                    nums.push(num);
                } else {
                    // s[i] == '+' || s[i] == '-'
                    if (!op.empty() && op.top() != '(' && nums.size() >= 2) {
                        int b = nums.top();
                        nums.pop();
                        int a = nums.top();
                        nums.pop();

                        if (op.top() == '+') {
                            nums.push(a + b);
                        } else {
                            nums.push(a - b);
                        }

                        op.pop();
                    }

                    op.push(s[i]);
                }


            }
        }

        int res = 0;
        if (!op.empty()) {
            res = nums.top();
            nums.pop();
            if (op.top() == '+')
                res += nums.top();
            else
                res = nums.top() - res;
        }

        return res;
    }
};

int main() {
    Solution solution;
    std::cout << solution.calculate("(1)") << std::endl;
}