//
// Created by wangqiucheng on 2020/8/26.
//

#ifndef LEETCODE_TEST_107_H
#define LEETCODE_TEST_107_H

#include "common.h"
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;

        queue<TreeNode*> traval_queue;
        traval_queue.push(root);
        while (!traval_queue.empty()) {
            int size = traval_queue.size();
            vector<int> level_node;
            for (int i = 0; i < size; ++i) {
                level_node.push_back(traval_queue.front()->val);
                if (traval_queue.front()->left) {
                    traval_queue.push(traval_queue.front()->left);
                }
                if (traval_queue.front()->right) {
                    traval_queue.push(traval_queue.front()->right);
                }
                traval_queue.pop();
            }
            ret.push_back(level_node);
        }
        int size = ret.size();
        for (int i = 0; i < size / 2; ++i) {
            vector<int>& tmp = ret[i];
            ret[i] = ret[size - i - 1];
            ret[size - i - 1] = tmp;
        }
        return ret;
    }
};
#endif //LEETCODE_TEST_107_H
