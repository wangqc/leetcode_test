//
// Created by wangqiucheng on 2020/9/8.
//

#ifndef LEETCODE_TEST_COMMON_H
#define LEETCODE_TEST_COMMON_H

#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

#endif //LEETCODE_TEST_COMMON_H
