//
// Created by wangqiucheng on 2020/8/12.
//

#ifndef LEETCODE_TEST_COMMON_H
#define LEETCODE_TEST_COMMON_H

#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

// 通过leetcode的字符串数组构建树
TreeNode* build_tree(vector<string> v) {
    if (v.empty() || v[0] == "null") {
        return nullptr;
    }
    TreeNode* root = new TreeNode(atoi(v[0].c_str()));
    queue<TreeNode*> q;
    q.push(root);
    int v_idx = 1;
    int v_size = v.size();
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (v_idx >= v_size) break;
            if (v[v_idx] == "null") {
                node->left = nullptr;
            } else {
                node->left = new TreeNode(atoi(v[v_idx].c_str()));
                q.push(node->left);
            }

            if (++v_idx >= v_size) break;
            if (v[v_idx] == "null") {
                node->right = nullptr;
            } else {
                node->right = new TreeNode(atoi(v[v_idx].c_str()));
                q.push(node->right);
            }
            ++v_idx;
        }

        if (v_idx >= v_size) {
            break;
        }
    }
    return root;
}


// 打印树
void print(TreeNode* root) {
    vector<string> v;
    queue<TreeNode*> q;
    q.push(root);
    bool not_all_null = true;
    while (!q.empty() && not_all_null) {
        not_all_null = false;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) {
                v.push_back("null");
            } else {
                v.push_back(std::to_string(node->val));
                q.push(node->left);
                q.push(node->right);
                not_all_null |= (node->left != nullptr);
                not_all_null |= (node->right != nullptr);
            }
        }
    }
    std::string s = "[";
    for (auto& e : v) {
        s += (e + ",");
    }
    s.pop_back();
    s+="]";
    cout << s << endl;
}

#endif //LEETCODE_TEST_COMMON_H
