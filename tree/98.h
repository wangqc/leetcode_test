//
// Created by wangqiucheng on 2020/8/26.
//

#ifndef LEETCODE_TEST_98_H
#define LEETCODE_TEST_98_H

#include "common.h"
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(TreeNode* root, vector<int>& seq) {
        if (!root) {
            return;
        }
        dfs(root->left, seq);
        seq.push_back(root->val);
        dfs(root->right, seq);
    }

    // 其实应该是中序遍历需要是有序的
    bool isValidBST(TreeNode* root) {
        vector<int> seq;
        dfs(root, seq);
        for (int i = 0; i < seq.size() - 1; ++i) {
            if (seq[i + 1] <= seq[i]) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODE_TEST_98_H
