//
// Created by 王秋城 on 2021/3/12.
//

#ifndef LEETCODE_TEST_538_H
#define LEETCODE_TEST_538_H

#include "common.h"


class Solution{
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return root;
    }

private:
    void dfs(TreeNode* root, int& sum) {
        if (!root) {
            return;
        }
        dfs(root->right, sum);
        root->val += sum;
        sum = root->val;
        dfs(root->left, sum);
    }
};
#endif //LEETCODE_TEST_538_H
