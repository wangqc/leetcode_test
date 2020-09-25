//
// Created by 王秋城 on 2020/9/25.
//

#ifndef LEETCODE_TEST_106_H
#define LEETCODE_TEST_106_H

#include "common.h"
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode* dfs(vector<int>& inorder, int i_left, int i_right, vector<int>& postorder, int p_left,
                  int p_right) {
        if (i_left > i_right) {
            return nullptr;
        }
        if (i_left == i_right) {
            TreeNode* node = new TreeNode(inorder[i_left]);
            return node;
        }
        TreeNode* root = new TreeNode(postorder[p_right]);
        int i_cur = i_left;
        int new_i_right = i_left - 1;
        while (inorder[i_cur++] != postorder[p_right]) {
            new_i_right++;
        }
        int left_tree_size = new_i_right - i_left + 1;
        int right_tree_size = i_right - i_cur + 1;
        root->left = dfs(inorder, i_left, new_i_right, postorder, p_left, p_left + left_tree_size - 1);
        root->right = dfs(inorder, i_cur, i_right, postorder, p_right - right_tree_size, p_right - 1);
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};


#endif //LEETCODE_TEST_106_H
