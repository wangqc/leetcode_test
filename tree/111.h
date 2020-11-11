//
// Created by wangqiucheng on 2020/11/11.
//

#ifndef LEETCODE_TEST_111_H
#define LEETCODE_TEST_111_H

#include "common.h"

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        int min_depth = 1000000;
        if (root->left != nullptr) {
            min_depth = min(minDepth(root->left), min_depth);
        }
        if (root->right != nullptr) {
            min_depth = min(minDepth(root->right), min_depth);
        }

        return min_depth + 1;
    }
};

#endif //LEETCODE_TEST_111_H
