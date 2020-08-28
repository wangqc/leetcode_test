//
// Created by wangqiucheng on 2020/8/12.
//

#ifndef LEETCODE_TEST_110_H
#define LEETCODE_TEST_110_H

#include "common.h"
#include <algorithm>

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        return std::max(left_depth, right_depth) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isBalanced(root->left) && isBalanced(root->right) && (std::abs(maxDepth(root->left) - maxDepth(root->right))) <= 1;
    }
};

#endif //LEETCODE_TEST_110_H
