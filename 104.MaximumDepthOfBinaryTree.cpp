//
// Created by Kenway on 7/28/2020.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        return count_depth(root);
    }

    int count_depth(TreeNode *node) {
        int leftDepth = 0, rightDepth = 0;
        if (node == NULL)
            return 0;
        leftDepth = count_depth(node->left);
        rightDepth = count_depth(node->right);
        return leftDepth > rightDepth ? (leftDepth + 1) : (rightDepth + 1);
    }
};