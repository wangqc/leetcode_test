//
// Created by 王秋城 on 2020/11/10.
//

#ifndef LEETCODE_TEST_101_H
#define LEETCODE_TEST_101_H

#include "common.h"
#include <vector>

using namespace std;

class Solution {
public:
    bool check(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};

#endif //LEETCODE_TEST_101_H
