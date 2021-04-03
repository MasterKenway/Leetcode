//
// Created by Kenway on 3/31/2021.
//
#include <iostream>

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
    bool dfs(TreeNode *cur, long long  lower, long long  upper) {
        if (!cur) return true;
        if (cur->val <= lower || cur->val >= upper) return false;
        return dfs(cur->left, lower, cur->val) && dfs(cur->right, cur->val, upper);
    }

    bool isValidBST(TreeNode *root) {
        return dfs(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};