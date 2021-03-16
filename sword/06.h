//
// Created by 王秋城 on 2021/3/16.
//

#ifndef LEETCODE_TEST_06_H
#define LEETCODE_TEST_06_H

#include "../common.h"


// 辅助栈
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> sk;
        ListNode* cur = head;
        int size = 0;
        while (cur) {
            sk.push(cur->val);
            cur = cur->next;
            size++;
        }
        vector<int> ret(size);
        int idx = 0;
        while (!sk.empty()) {
            ret[idx++] = sk.top();
            sk.pop();
        }
        return ret;
    }
};

class Solution2 {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ret;
        recur(head, ret);
        return ret;
    }

private:
    void recur(ListNode* node, vector<int>& ret) {
        if (!node) {
            return;
        }
        recur(node->next, ret);
        ret.emplace_back(node->val);
    }
};


#endif //LEETCODE_TEST_06_H
