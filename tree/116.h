//
// Created by wangqiucheng on 2020/10/17.
//

#ifndef LEETCODE_TEST_116_H
#define LEETCODE_TEST_116_H

#include "common.h"
#include <queue>

using namespace std;


// 题干说明是完美二叉树, 其实就是满二叉树, 先按照最通俗的来做, 层级遍历
class Solution {
public:
    // O(N) space
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            Node* prev_node = nullptr;
            for (int i = 0; i < size; ++i) {
                Node* cur_node = que.front();
                if (cur_node->left) {
                    que.push(cur_node->left);
                    que.push(cur_node->right);
                }
                que.pop();
                if (prev_node != nullptr) {
                    prev_node->next = cur_node;
                }
                prev_node = cur_node;
            }
        }
        return root;
    }

    // O(1) space
    Node* connectV2(Node* root) {
        if (!root) {
            return nullptr;
        }
        Node* prev_layer_leftest_node = root;
        while (prev_layer_leftest_node->left) {
            Node* prev_layer_travel = prev_layer_leftest_node;
            Node* cur_layer_prev_node = nullptr;
            while (prev_layer_travel) {
                if (cur_layer_prev_node) {
                    cur_layer_prev_node->next = prev_layer_travel->left;
                }
                prev_layer_travel->left->next = prev_layer_travel->right;
                cur_layer_prev_node = prev_layer_travel->right;
                prev_layer_travel = prev_layer_travel->next;
            }
            prev_layer_leftest_node = prev_layer_leftest_node->left;
        }
        return root;
    }
};

#endif //LEETCODE_TEST_116_H
