//
// Created by 王秋城 on 2021/4/23.
//

#ifndef LEETCODE_TEST_445_H
#define LEETCODE_TEST_445_H

#include "../common.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        while (t1) {
            s1.push(t1->val);
            t1 = t1->next;
        }
        while (t2) {
            s2.push(t2->val);
            t2 = t2->next;
        }
        ListNode* dummy_head = new ListNode();
        int up = 0;
        while (!s1.empty() && !s2.empty()) {
            int sum = s1.top() + s2.top() + up;
            ListNode* node = new ListNode(sum % 10);
            up = sum / 10;
            s1.pop();
            s2.pop();
            node->next = dummy_head->next;
            dummy_head->next = node;
        }
        while (!s1.empty()) {
            int sum = s1.top() + up;
            ListNode* node = new ListNode(sum % 10);
            up = sum / 10;
            s1.pop();
            node->next = dummy_head->next;
            dummy_head->next = node;
        }
        while (!s2.empty()) {
            int sum = s2.top() + up;
            ListNode* node = new ListNode(sum % 10);
            up = sum / 10;
            s2.pop();
            node->next = dummy_head->next;
            dummy_head->next = node;
        }
        if (up) {
            ListNode* node = new ListNode(1);
            node->next = dummy_head->next;
            dummy_head->next = node;
        }
        return dummy_head->next;
    }
};

#endif //LEETCODE_TEST_445_H
