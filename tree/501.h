//
// Created by wangqiucheng on 2020/9/24.
//

#ifndef LEETCODE_TEST_501_H
#define LEETCODE_TEST_501_H

#include "common.h"
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    void dfs(TreeNode* root, map<int, int>& mp, int& max) {
        if (!root) {
            return;
        }
        dfs(root->left, mp, max);
        if (mp.find(root->val) == mp.end()) {
            mp[root->val] = 1;
        } else {
            mp[root->val]++;
        }
        max = (mp[root->val] > max) ? mp[root->val] : max;
        dfs(root->right, mp, max);
    }

    vector<int> findMode(TreeNode* root) {
        map<int, int> mp;
        int max = 0;
        dfs(root, mp, max);
        vector<int> v;
        for (auto& kv : mp) {
            if (kv.second == max) {
                v.push_back(kv.first);
            }
        }
        return v;
    }

    void dfsV2(TreeNode* root, int base, int& cnt, int& max_cnt, vector<int>& v) {
        if (!root) {
            return;
        }
        dfsV2(root->left, base, cnt, max_cnt, v);
        if (cnt == 0) {
            base = root->val;
            cnt = 1;
        } else if (root->val == base) {
            cnt += 1;
        } else {
            if (cnt == max_cnt) {
                v.push_back(base);
            } else if (cnt > max_cnt) {
                v = {base};
                max_cnt = cnt;
            }
            base = root->val;
            cnt = 1;
        }
        dfsV2(root->right, base, cnt, max_cnt, v);
    }

    vector<int> findModeV2(TreeNode* root) {
        vector<int> v;
        if (!root) return v;
        int cnt = 0, max_cnt = 0;
        dfsV2(root, 0, cnt, max_cnt, v);
    }
};

#endif //LEETCODE_TEST_501_H
