//
// Created by wangqiucheng on 2020/8/28.
//

#ifndef LEETCODE_TEST_701_H
#define LEETCODE_TEST_701_H

#include "common.h"

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            root = new TreeNode(val);
            return root;
        }
        if (root->val > val) {
            if (root->left) {
                insertIntoBST(root->left, val);
            } else {
                root->left = new TreeNode(val);
            }
        } else {
            if (root->right) {
                insertIntoBST(root->right, val);
            } else {
                root->right = new TreeNode(val);
            }
        }
        return root;
    }
};

#endif //LEETCODE_TEST_701_H
