//
// Created by wangqiucheng on 2020/8/11.
//

#ifndef LEETCODE_TEST_138_H
#define LEETCODE_TEST_138_H

#include <map>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    // 最容易想到的方法, 就是维护一个字典做映射, 这里可以变成一个字典就可以的
    Node* copyRandomListStupid(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        std::map<Node*, int> node_idx_map;
        std::map<int, Node*> idx_node_map;
        Node* cur = head;
        int idx = 0;
        int cnt = 0;
        while (cur) {
            node_idx_map[cur] = idx;
            Node* i_cur = new Node(cur->val);
            idx_node_map[idx] = i_cur;
            idx++;
            cnt++;
            cur = cur->next;
        }
        for (int i = 0; i < cnt - 1; ++i) {
            idx_node_map[i]->next = idx_node_map[i+1];
        }
        cur = head;
        idx = 0;
        while (cur) {
            if (cur->random != nullptr) {
                idx_node_map[idx]->random = idx_node_map[node_idx_map[cur->random]];
            }
            cur = cur->next;
            idx++;
        }
        return idx_node_map[0];
    }

    // 另一种方法, 就是将生成的节点就放在原来节点的后面, 最后再split出来即可
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node* cur = head;
        while (cur) {
            Node* tmp = cur->next;
            Node* new_cur = new Node(cur->val);
            cur->next = new_cur;
            new_cur->next = tmp;
            cur = tmp;
        }
        cur = head;
        while (cur) {
            if (cur->random != nullptr) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        Node* new_head = head->next, *new_cur = head->next;
        cur = head;
        while (cur) {
            cur->next = cur->next->next;
            new_cur->next = (new_cur->next == nullptr) ? nullptr : new_cur->next->next;
            cur = cur->next;
            new_cur = new_cur->next;
        }
        return new_head;

    }
};

#endif //LEETCODE_TEST_138_H
