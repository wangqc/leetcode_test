//
// Created by 王秋城 on 2021/3/16.
//

#ifndef LEETCODE_TEST_07_H
#define LEETCODE_TEST_07_H

#include "../tree/common.h"

class Solution {
    unordered_set<int, int> in_idx;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            in_idx[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& pre, int pre_left, int pre_right, vector<int>& in, int in_left, int in_right) {
        if (pre_left > pre_right) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[pre_left]);
        int i = in_idx[pre[pre_left]];
        int left_size = i - in_left;
        root->left = build(pre, pre_left + 1, pre_left + left_size, in, in_left, i - 1);
        root->right = build(pre, pre_left + left_size + 1, pre_right, in, i + 1, in_right);
        return root;
    }
};
#endif //LEETCODE_TEST_07_H
