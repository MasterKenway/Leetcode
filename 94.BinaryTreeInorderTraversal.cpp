//
// Created by Kenway on 3/29/2021.
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *p = root;
        stack<TreeNode *> stack;
        while (p || !stack.empty()) {
            while (p) {
                stack.push(p);
                p = p->left;
            }

            p = stack.top();
            stack.pop();
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }
};