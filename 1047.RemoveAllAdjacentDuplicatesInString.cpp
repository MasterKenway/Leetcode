//
// Created by Kenway on 3/9/2021.
//
#include <string>
#include <algorithm>

class Solution {
public:
    std::string removeDuplicates(std::string S) {
        std::string stack;

        for (int i = 0; i < S.length(); ++i) {
            if (!stack.empty() && S[i] == stack.back()) {
                while (!stack.empty() && S[i] == stack.back()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(S[i]);
            }
        }

        return stack;
    }
};