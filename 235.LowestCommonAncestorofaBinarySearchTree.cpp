//
// Created by Kenway on 3/30/2021.
//
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *cur = root;
        while (true) {
            if (cur->val > p->val && cur->val > q->val) {
                cur = cur->left;
            }
            else if (cur->val < p->val && cur->val < q->val) {
                cur = cur->right;
            } else {
                break;
            }
        }
        return cur;
    }
};