//
// Created by 王秋城 on 2021/3/24.
//

#ifndef LEETCODE_TEST_230_H
#define LEETCODE_TEST_230_H

#include "common.h"

class Solution {
public:
    vector<int> orders;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        return orders[k+1];
    }

private:
    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        dfs(root->left);
        orders.emplace_back(root->val);
        dfs(root->right);
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> sk;
        TreeNode* cur = root;
        int cnt = 0;
        int ret;
        while (true) {
            while (cur) {
                sk.push(cur);
                cur = cur->left;
            }
            cur = sk.top();
            ret = cur->val;
            cnt++;
            if (cnt == k) {
                break;
            }
            cur = cur->right;
            sk.pop();
        }
        return ret;
    }
};

#endif //LEETCODE_TEST_230_H
