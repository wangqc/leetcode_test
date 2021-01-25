//
// Created by 王秋城 on 2021/1/23.
//

#ifndef LEETCODE_TEST_COMMON_H
#define LEETCODE_TEST_COMMON_H

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack>
#include <iostream>
#include "stdlib.h"

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a Node.
// Graph
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

void print(int num) {
    cout << num << endl;
}

void print(const vector<int>& nums) {
    for (auto& n : nums) {
        cout << n << ",";
    }
    cout << endl;
}

void print(vector<int>&& nums) {
    print(nums);
}

void print2rd(const vector<vector<int>>& nums) {
    for (auto& vec : nums) {
        print(vec);
    }
}

void print2rd(vector<vector<int>>&& nums) {
    print2rd(nums);
}

void print(const vector<string>& strs) {
    for (auto& s : strs) {
        cout << s << ",";
    }
    cout << endl;
}

void print(vector<string>&& strs) {
    print(strs);
}


#endif //LEETCODE_TEST_COMMON_H
