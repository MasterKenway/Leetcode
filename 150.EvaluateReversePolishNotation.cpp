//
// Created by Kenway on 3/20/2021.
//
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stack;
        for (auto item : tokens) {
            if (isNum(item)) {
                stack.push(stoi(item));
            } else {
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();

                switch (item[0]) {
                    case '*':
                        stack.push(a * b);
                        break;
                    case '/':
                        stack.push(a / b);
                        break;
                    case '+':
                        stack.push(a + b);
                        break;
                    case '-':
                        stack.push(a - b);
                        break;
                }
            }
        }
        return  stack.top();
    }


    bool isNum(string str) {
        return (str[0] == '-' && str.length() > 1) || isdigit(str[0]);
    }
};

int main() {
    vector<string> array = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    Solution solution;
    solution.evalRPN(array);
}