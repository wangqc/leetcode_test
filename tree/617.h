//
// Created by wangqiucheng on 2020/9/23.
//

#ifndef LEETCODE_TEST_617_H
#define LEETCODE_TEST_617_H

#include "common.h"
#include <queue>

using namespace std;

class Solution {
public:
    void dfs(TreeNode** master_ptr, TreeNode** slave_ptr) {
        TreeNode* master_node = *master_ptr;
        TreeNode* slave_node = *slave_ptr;
        if (!slave_node) {
            return;
        }
        if (master_node) {
            master_node->val += slave_node->val;
        } else {
            *master_ptr = new TreeNode(slave_node->val);
            master_node = *master_ptr;
        }
        dfs(&((*master_ptr)->left), &(slave_node->left));
        dfs(&((*master_ptr)->right), &(slave_node->right));
    }

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        dfs(&t1, &t2);
        return t1;
    }


    // bfs
    TreeNode* mergeTreesV2(TreeNode* t1, TreeNode* t2) {
        if (!t1) {
            return t2;
        }
        if (!t2) {
            return t1;
        }
        queue<TreeNode*> q1, q2;
        q1.push(t1);
        q2.push(t2);
        while (!q1.empty() && !q2.empty()) {
            int size = q1.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* n1 = q1.front();
                TreeNode* n2 = q2.front();
                n1->val += n2->val;
                if (n1->left) {
                    if (n2->left) {
                        q1.push(n1->left);
                        q2.push(n2->left);
                    }
                } else {
                    if (n2->left) {
                        n1->left = new TreeNode(n2->val);
                        q1.push(n1->left);
                        q2.push(n2->left);
                    }
                }

                if (n1->right) {
                    if (n2->right) {
                        q1.push(n1->right);
                        q2.push(n2->right);
                    }
                } else {
                    if (n2->right) {
                        n1->right = new TreeNode(n2->val);
                        q1.push(n1->right);
                        q2.push(n2->right);
                    }
                }
                q1.pop();
                q2.pop();
            }
        }
        return t1;
    }

    // 更加优雅的dfs
    TreeNode* mergeTreesV3(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        auto merged = new TreeNode(t1->val + t2->val);
        merged->left = mergeTrees(t1->left, t2->left);
        merged->right = mergeTrees(t1->right, t2->right);
        return merged;
    }
};

#endif //LEETCODE_TEST_617_H
