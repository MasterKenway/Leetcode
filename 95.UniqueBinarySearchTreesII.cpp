//
// Created by Kenway on 7/21/2020.
//
#include <iostream>
#include <vector>


//Definition for a binary tree node.
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
    std::vector<TreeNode*> result;

    std::vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return genBST(1, n);

    }

    std::vector<TreeNode*> genBST(int left, int right) {
        std::vector<TreeNode*> subResult;

        if (left > right)
            return {nullptr};

        for (int i = left; i <= right; ++i) {
            std::vector<TreeNode*> leftTrees = genBST(left, i - 1);
            std::vector<TreeNode*> rightTrees = genBST(i + 1, right);

            for (auto iterator = leftTrees.begin(); iterator < leftTrees.end(); iterator++) {
                for (auto iterator2 = rightTrees.begin(); iterator < rightTrees.end(); iterator++) {
                    TreeNode* subTree = new TreeNode(i, *iterator, *iterator2);
                    subResult.push_back(subTree);
                }
            }

        }
        return subResult;
    }
};