//
// Created by wangqiucheng on 2020/8/26.
//

#ifndef LEETCODE_TEST_236_H
#define LEETCODE_TEST_236_H

#include "common.h"
#include <vector>

class Solution {
public:
    // 标准dfs写法
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return root;
        }
        if (root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr) {
            return root;
        }
        if (left != nullptr) {
            return left;
        }
        if (right != nullptr) {
            return right;
        }
        return nullptr;
    }
};

#endif //LEETCODE_TEST_236_H
