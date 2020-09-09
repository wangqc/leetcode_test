//
// Created by wangqiucheng on 2020/9/8.
//

#ifndef LEETCODE_TEST_133_H
#define LEETCODE_TEST_133_H

#include "common.h"
#include <map>

// 图遍历, dfs + bfs

class Solution {
public:
    std::map<Node*, Node*> visited;

    // dfs
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        Node* clone_node = new Node(node->val);
        visited[node] = clone_node;

        for (auto& neighbour : node->neighbors) {
            clone_node->neighbors.emplace_back(cloneGraph(neighbour));
        }

        return clone_node;
    }

    Node* cloneGraphV2(Node* node) {

    }
};


#endif //LEETCODE_TEST_133_H
