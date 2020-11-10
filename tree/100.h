//
// Created by 王秋城 on 2020/11/10.
//

#ifndef LEETCODE_TEST_100_H
#define LEETCODE_TEST_100_H

#include "common.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool p_exist = (p != nullptr);
        bool q_exist = (q != nullptr);
        if (p_exist ^ q_exist) {
            return false;
        }
        if (!p_exist) {
            return true;
        }
        if (p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

#endif //LEETCODE_TEST_100_H
