//
// Created by wangqiucheng on 2020/8/12.
//

#ifndef LEETCODE_TEST_COMMON_H
#define LEETCODE_TEST_COMMON_H

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
};

#endif //LEETCODE_TEST_COMMON_H
