//
// Created by 王秋城 on 2021/2/9.
//

#ifndef LEETCODE_TEST_337_H
#define LEETCODE_TEST_337_H

#include "common.h"

// https://leetcode-cn.com/problems/house-robber-iii/

class SolutionSimple {
public:
    // 简单，暴搜解法
    int rob(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int money = root->val;
        if (root->left) {
            money += (rob(root->left->left) + rob(root->left->right));
        }
        if (root->right) {
            money += (rob(root->right->left) + rob(root->right->right));
        }
        return std::max(money, rob(root->left) + rob(root->right));
    }
};

class SolutionMem {
public:
    std::map<TreeNode*, int> root_2_value;

    int rob(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (root_2_value.find(root) != root_2_value.end()) {
            return root_2_value[root];
        }
        int money = root->val;
        if (root->left) {
            money += (rob(root->left->left) + rob(root->left->right));
        }
        if (root->right) {
            money += (rob(root->right->left) + rob(root->right->right));
        }
        int res = std::max(money, rob(root->left) + rob(root->right));
        root_2_value[root] = res;
        return res;
    }
};

class Solution {
public:
    int rob(TreeNode* root) {
        auto ret = rob_internal(root);
        return std::max(ret[0], ret[1]);
    }

private:
    vector<int> rob_internal(TreeNode* root) {
        if (!root) {
            return vector<int>(2);
        }
        auto left = rob_internal(root->left);
        auto right = rob_internal(root->right);

        vector<int> ret(2);
        ret[0] = std::max(left[0], left[1]) + std::max(right[0], right[1]);
        ret[1] = left[0] + right[0] + root->val;

        return ret;
    }
};


#endif //LEETCODE_TEST_337_H
