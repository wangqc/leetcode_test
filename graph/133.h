//
// Created by wangqiucheng on 2020/9/8.
//

#ifndef LEETCODE_TEST_133_H
#define LEETCODE_TEST_133_H

#include "../common.h"

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
        if (!node) {
            return nullptr;
        }
        Node* clone_node = new Node(node->val);
        visited[node] = clone_node;
        set<Node*> finish_node;

        queue<Node*> que;
        que.push(node);
        while (!que.empty()) {
            Node* cur = que.front();
            que.pop();
            if (finish_node.find(cur) != finish_node.end()) {
                continue;
            }
            for (auto& neightbour : cur->neighbors) {
                if (visited.find(neightbour) == visited.end()) {
                    visited[neightbour] = new Node(neightbour->val);
                }
                visited[cur]->neighbors.emplace_back(visited[neightbour]);
                que.push(neightbour);
            }
            finish_node.insert(cur);
        }
        return visited[node];
    }
};


#endif //LEETCODE_TEST_133_H
