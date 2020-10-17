//
// Created by 王秋城 on 2020/10/13.
//

#ifndef LEETCODE_TEST_530_H
#define LEETCODE_TEST_530_H

#include "common.h"
#include <vector>

using namespace std;

class Solution {
public:
    void inorderTravel(TreeNode* root, vector<int>& v) {
        if (!root) {
            return;
        }
        inorderTravel(root->left, v);
        v.push_back(root->val);
        inorderTravel(root->right, v);
    }

    // stupid solution, two traval and o(n) space
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        inorderTravel(root, v);
        int min = v[1] - v[0];
        for (int i = 1; i < v.size() - 1; ++i) {
            if (v[i+1] - v[i] < min) {
                min = v[i+1] - v[i];
            }
        }
        return min;
    }
};


#endif //LEETCODE_TEST_530_H
