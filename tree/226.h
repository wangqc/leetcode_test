//
// Created by 王秋城 on 2020/9/18.
//

#ifndef LEETCODE_TEST_226_H
#define LEETCODE_TEST_226_H

#include "common.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        invertTree(root->left);
        invertTree(root->right);
        TreeNode* tmp_node = root->left;
        root->left = root->right;
        root->right = tmp_node;
        return root;
    }
};

#endif //LEETCODE_TEST_226_H
