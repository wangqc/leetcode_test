//
// Created by 王秋城 on 2021/3/12.
//

#ifndef LEETCODE_TEST_538_H
#define LEETCODE_TEST_538_H

#include "common.h"


class Solution{
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return root;
    }

private:
    void dfs(TreeNode* root, int& sum) {
        if (!root) {
            return;
        }
        dfs(root->right, sum);
        root->val += sum;
        sum = root->val;
        dfs(root->left, sum);
    }
};

class SolutionMoris {
public:
    TreeNode* getSuccessor(TreeNode* node) {
        TreeNode* succ = node->right;
        while (succ->left != nullptr && succ->left != node) {
            succ = succ->left;
        }
        return succ;
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode* node = root;

        while (node != nullptr) {
            if (node->right == nullptr) {
                sum += node->val;
                node->val = sum;
                node = node->left;
            } else {
                TreeNode* succ = getSuccessor(node);
                if (succ->left == nullptr) {
                    succ->left = node;
                    node = node->right;
                } else {
                    succ->left = nullptr;
                    sum += node->val;
                    node->val = sum;
                    node = node->left;
                }
            }
        }

        return root;
    }
};

#endif //LEETCODE_TEST_538_H
