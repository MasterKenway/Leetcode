//
// Created by Kenway on 3/31/2021.
//
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *ans;
    bool dfs(TreeNode *cur, TreeNode *p, TreeNode *q) {
        if (cur == nullptr) return false;

        bool leftSon = dfs(cur->left, p, q);
        bool rightSon = dfs(cur->right, p, q);

        if ((leftSon && rightSon) || ((cur->val == p->val || cur->val == q->val) && (leftSon || rightSon))) {
            ans = cur;
        }

        return leftSon || rightSon || (cur->val == p->val || cur->val == q->val);

    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return ans;
    }
};
