//
// Created by 王秋城 on 2021/1/27.
//

#ifndef LEETCODE_TEST_105_H
#define LEETCODE_TEST_105_H

#include "common.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return inner_build_tree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* inner_build_tree(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start,
                               int in_end) {
        if (pre_start > pre_end) {
            return nullptr;
        }
        int root_value = preorder[pre_start];
        TreeNode* root = new TreeNode(root_value);
        int in_mid = in_start;
        for (; in_mid <= in_end; ++in_mid) {
            if (inorder[in_mid] == root_value) {
                break;
            }
        }
        int left_len = in_mid - in_start;
        root->left = inner_build_tree(preorder, pre_start + 1, pre_start + left_len, inorder, in_start, in_mid);
        root->right = inner_build_tree(preorder, pre_start + left_len + 1, pre_end, inorder, in_mid + 1, in_end);
        return root;
    }
};

#endif //LEETCODE_TEST_105_H

