//
// Created by wangqiucheng on 2020/9/8.
//

#ifndef LEETCODE_TEST_144_H
#define LEETCODE_TEST_144_H

#include "common.h"
#include <vector>
#include <stack>

using namespace std;


// 树的前序遍历
// TODO: 莫里斯遍历这个好像也都适用
class Solution {
public:
    void traval(TreeNode* root, vector<int>& v) {
        if (!root) {
            return;
        }
        v.push_back(root->val);
        traval(root->left, v);
        traval(root->right, v);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        traval(root, v);
        return v;
    }


    // 使用迭代方法也是有基本套路的
    vector<int> preorderTraversalV2(TreeNode* root) {
        vector<int> v;
        if (!root) {
            return v;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            if (node) {
                stk.pop();
                if (node->right) {
                    stk.push(node->right);
                }
                if (node->left) {
                    stk.push(node->left);
                }
                stk.push(node);
                stk.push(nullptr);
            } else {
                stk.pop();
                v.push_back(stk.top()->val);
                stk.pop();
            }
        }
        return v;
    }

};

#endif //LEETCODE_TEST_144_H
