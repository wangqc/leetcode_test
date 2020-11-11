//
// Created by wangqiucheng on 2020/11/11.
//

#ifndef LEETCODE_TEST_112_H
#define LEETCODE_TEST_112_H

#include "common.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        if (!root->left && !root->right) {
            return (sum == root->val);
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

#endif //LEETCODE_TEST_112_H
