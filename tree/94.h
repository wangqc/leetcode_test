//
// Created by wangqiucheng on 2020/9/7.
//

#ifndef LEETCODE_TEST_94_H
#define LEETCODE_TEST_94_H

#include "common.h"
#include <vector>

using namespace std;

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
};

#endif //LEETCODE_TEST_94_H
