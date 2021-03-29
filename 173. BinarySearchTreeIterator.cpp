//
// Created by Kenway on 3/29/2021.
//

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

class BSTIterator {
public:
    vector<int> array;
    vector<int>::iterator iter;

    void dfs(TreeNode *cur) {
        if (!cur) return;
        dfs(cur->left);
        array.push_back(cur->val);
        dfs(cur->right);
    }

    BSTIterator(TreeNode *root) {
        dfs(root);
        iter = array.begin();
    }

    int next() {
        int curVal = *iter;
        iter++;
        return curVal;
    }

    bool hasNext() {
        return iter != array.end();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */