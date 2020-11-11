//
// Created by wangqiucheng on 2020/11/11.
//

#ifndef LEETCODE_TEST_108_H
#define LEETCODE_TEST_108_H

#include "common.h"
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode* sort(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int middle = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[middle]);
        root->left = sort(nums, start, middle - 1);
        root->right = sort(nums, middle + 1, end);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sort(nums, 0, nums.size() - 1);
    }
};

#endif //LEETCODE_TEST_108_H
