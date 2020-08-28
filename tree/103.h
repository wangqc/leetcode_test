//
// Created by wangqiucheng on 2020/8/26.
//

#ifndef LEETCODE_TEST_103_H
#define LEETCODE_TEST_103_H

#include "common.h"
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void reverseVector(vector<int>& v) {
        int size = v.size();
        for (int i = 0; i < size/2; ++i) {
            int tmp = v[i];
            v[i] = v[size - i - 1];
            v[size - i - 1] = tmp;
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;

        queue<TreeNode*> que;
        que.push(root);
        bool is_seq = true;
        while (!que.empty()) {
            int size = que.size();
            vector<int> level_node;

            for (int i = 0; i < size; ++i) {
                level_node.push_back(que.front()->val);
                if (que.front()->left) {
                    que.push(que.front()->left);
                }
                if (que.front()->right) {
                    que.push(que.front()->right);
                }
                que.pop();
            }
            if (!is_seq) {
                reverseVector(level_node);
            }
            ret.push_back(level_node);
            is_seq = !is_seq;
        }
        return ret;
    }
};

#endif //LEETCODE_TEST_103_H
