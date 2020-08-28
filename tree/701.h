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
            TreeNode* ret = new TreeNode(val);
            return ret;
        }
        if (val < root->val) {
            insertIntoBST(root->left, val);
        } else {
            insertIntoBST(root->right, val);
        }
        return root;
    }
};

#endif //LEETCODE_TEST_701_H
