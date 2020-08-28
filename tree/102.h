//
// Created by wangqiucheng on 2020/8/26.
//

#ifndef LEETCODE_TEST_102_H
#define LEETCODE_TEST_102_H

#include "common.h"
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level_order;
        if (!root){
            return level_order;
        }
        queue<TreeNode*> tree_level_queue;
        tree_level_queue.push(root);
        while (!tree_level_queue.empty()) {
            queue<TreeNode*> tmp_queue;
            while (!tree_level_queue.empty()) {
                tmp_queue.push(tree_level_queue.front());
                tree_level_queue.pop();
            }
            vector<int> level_node;
            while (!tmp_queue.empty()) {
                level_node.push_back(tmp_queue.front()->val);
                if (tmp_queue.front()->left) {
                    tree_level_queue.push(tmp_queue.front()->left);
                }
                if (tmp_queue.front()->right) {
                    tree_level_queue.push(tmp_queue.front()->right);
                }
                tmp_queue.pop();
            }
            level_order.push_back(level_node);
        }
        return level_order;
    }
};

#endif //LEETCODE_TEST_102_H
