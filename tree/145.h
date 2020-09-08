//
// Created by wangqiucheng on 2020/9/8.
//

#ifndef LEETCODE_TEST_145_H
#define LEETCODE_TEST_145_H

#include "common.h"
#include <vector>
#include <stack>

using namespace std;


// 树的后序遍历
class Solution {
public:
    void traval(TreeNode* root, vector<int>& v) {
        if (!root) {
            return;
        }
        traval(root->left, v);
        traval(root->right, v);
        v.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        traval(root, v);
        return v;
    }

    // 迭代通用模板
    vector<int> postorderTraversalV2(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> stk;
        if (!root) {
            return v;
        }
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            if (node) {
                stk.push(nullptr);
                if (node->right) {
                    stk.push(node->right);
                }
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

#endif //LEETCODE_TEST_145_H
