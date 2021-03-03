//
// Created by 王秋城 on 2021/3/3.
//

#ifndef LEETCODE_TEST_437_H
#define LEETCODE_TEST_437_H

#include "common.h"


// 双递归解法
class SolutionCommon {
public:
    int pathSum(TreeNode* root, int sum) {
        int num = 0;
        outer_dfs(root, sum, num);
        return num;
    }

private:
    void outer_dfs(TreeNode* root, int sum, int& num) {
        if (!root) {
            return;
        }
        dfs(root, sum, 0, num);
        outer_dfs(root->left, sum, num);
        outer_dfs(root->right, sum, num);
    }

    void dfs(TreeNode* root, int sum, int cur_sum, int& num) {
        if (!root) {
            return;
        }
        if (root->val + cur_sum == sum) {
            num++;
        }
        cur_sum += root->val;
        dfs(root->left, sum, cur_sum, num);
        dfs(root->right, sum, cur_sum, num);
    }
};

// 前缀和
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        map<int, int> mp;
        mp[0] = 1;
        return dfs(root, sum, mp, 0);
    }

private:
    int dfs(TreeNode* root, int sum, map<int, int>& mp, int cur_sum) {
        if (!root) {
            return 0;
        }
        int res = 0;
        cur_sum += root->val;

        if (mp.find(cur_sum - sum) != mp.end()) {
            res += mp[cur_sum - sum];
        }
        mp[cur_sum]++;

        dfs(root->left, sum, mp, cur_sum);
        dfs(root->right, sum, mp, cur_sum);

        mp[cur_sum]--;
        return res;
    }
};
#endif //LEETCODE_TEST_437_H
