//
// Created by 王秋城 on 2021/1/25.
//

#ifndef LEETCODE_TEST_543_H
#define LEETCODE_TEST_543_H

#include "common.h"
#include <algorithm>

using namespace std;

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return maxd;
    }

private:
    int maxd = 0;

    int depth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        maxd = max(left_depth + right_depth, maxd);
        return max(left_depth, right_depth) + 1;
    }
};

#endif //LEETCODE_TEST_543_H
