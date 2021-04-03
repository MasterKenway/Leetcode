//
// Created by Kenway on 4/1/2021.
//
#include <stack>
#include <vector>


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
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root) return {};

        vector<int> res;
        stack<TreeNode *> stack;
        TreeNode *cur = root, *pre;
        while (cur || !stack.empty()) {
            while (cur) {
                stack.push(cur);
                cur = cur->left;
            }

            cur = stack.top();
            stack.pop();
            if (cur->right == nullptr || cur->right == pre) {
                res.push_back(cur->val);
                pre = cur;
                cur = nullptr;
            } else {
                stack.push(cur);
                cur = cur->right;
            }
        }

        return res;
    }
};