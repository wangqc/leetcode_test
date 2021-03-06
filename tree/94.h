//
// Created by wangqiucheng on 2020/9/7.
//

#ifndef LEETCODE_TEST_94_H
#define LEETCODE_TEST_94_H

#include "common.h"
#include <vector>
#include <stack>

using namespace std;


// 树的中序遍历
// TODO: 莫里斯遍历这个好像也都适用
class Solution {
public:
    void traval(TreeNode* root, vector<int>& v) {
        if (!root) {
            return;
        }
        traval(root->left, v);
        v.push_back(root->val);
        traval(root->right, v);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        traval(root, v);
        return v;
    }

    vector<int> inorderTraversalV2(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> stk;
        if (!root) {
            return v;
        }
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            if (node) {
                stk.pop();
                if (node->right) {
                    stk.push(node->right);
                }
                stk.push(node);
                stk.push(nullptr);
                if (node->left) {
                    stk.push(node->left);
                }
            } else {
                stk.pop();
                v.push_back(stk.top()->val);
                stk.pop();
            }
        }
        return v;
    }
};

#endif //LEETCODE_TEST_94_H
