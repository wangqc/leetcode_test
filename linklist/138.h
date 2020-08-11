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
    Node* copyRandomList(Node* head) {
        std::map<Node*, int> node_idx_map;
        std::map<int, Node*> idx_node_map;

    }
};

#endif //LEETCODE_TEST_138_H
