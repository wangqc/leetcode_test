//
// Created by wangqiucheng on 2020/8/12.
//

#ifndef LEETCODE_TEST_104_H
#define LEETCODE_TEST_104_H

#include "common.h"
#include <algorithm>
#include <queue>

class Solution {
public:
    // 递归版本
    int maxDepthV1(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_depth = maxDepthV1(root->left);
        int right_depth = maxDepthV1(root->right);
        return std::max(left_depth, right_depth) + 1;
    }

    // 典型的bfs
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        std::queue<TreeNode*> tree_layer_queue;
        tree_layer_queue.push(root);
        int height = 0;
        while (!tree_layer_queue.empty()) {
            int size = tree_layer_queue.size();
            while (size > 0) {
                TreeNode* node = tree_layer_queue.front();
                tree_layer_queue.pop();
                if (node->left) {
                    tree_layer_queue.push(node->left);
                }
                if (node->right) {
                    tree_layer_queue.push(node->right);
                }
                size--;
            }
            height++;
        }
        return height;
    }
};

#endif //LEETCODE_TEST_104_H
