//
// Created by 王秋城 on 2021/1/27.
//

#ifndef LEETCODE_TEST_114_H
#define LEETCODE_TEST_114_H

#include "common.h"

class Solution {
public:
    // 这种解法比较好
    void flattenV1(TreeNode* root) {
        while (root != nullptr) {
            if (root->left == nullptr) {
                root = root->right;
            } else {
                TreeNode* right = root->right;
                root->right = root->left;
                root->left = nullptr;
                TreeNode* left_most_right = root->right;
                while (left_most_right->right != nullptr) {
                    left_most_right = left_most_right->right;
                }
                left_most_right->right = right;
                root = root->right;
            }
        }
    }

    TreeNode* pre = nullptr;
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = nullptr;
        pre = root;
    }
};

#endif //LEETCODE_TEST_114_H
