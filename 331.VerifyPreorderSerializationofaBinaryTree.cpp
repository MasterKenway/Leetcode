//
// Created by Kenway on 3/12/2021.
//
#include <string>
#include <stack>

class Solution {
public:
    bool isValidSerialization(std::string preorder) {
        std::stack<char> stack;
        stack.push(1);
        for (int i = 0; i < preorder.length(); ++i) {
            if (stack.empty()) return false;


            if (isdigit(preorder[i])) {
                while (isdigit(preorder[j])) {
                    i++;
                }
                i--;

                stack.top() -= 1;
                if (stack.top() == 0) stack.pop();
                stack.push(2);
            } else if (preorder[i] == '#'){
                stack.top() -= 1;
                if (stack.top() == 0) stack.pop();
            } else {
                continue;
            }
        }

        return stack.empty();
    }
};