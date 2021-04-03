//
// Created by Kenway on 4/1/2021.
//
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root) return {};

        vector<int> res;
        stack<TreeNode *> stack;
        TreeNode *cur = root;
        while (cur || !stack.empty()) {
            while (cur) {
                res.push_back(cur->val);
                stack.push(cur);
                cur = cur->left;
            }

            cur = stack.top();
            stack.pop();
            cur = cur->right;
        }
        return res;
    }
};