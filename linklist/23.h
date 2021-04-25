//
// Created by 王秋城 on 2021/4/25.
//

#ifndef LEETCODE_TEST_23_H
#define LEETCODE_TEST_23_H

#include "../common.h"

class Solution {
public:
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode* dummy_node = new ListNode();
        ListNode* prev = dummy_node;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        if (l1) prev->next = l1;
        if (l2) prev->next = l2;
        return dummy_node->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        int len = lists.size();
        for (int step = 1; step < len; step <<= 1) {
            int cur = 0;
            while (cur + step < len) {
                lists[cur] = mergeList(lists[cur], lists[cur + step]);
                cur += (step << 1);
            }
        }
        return lists[0];
    }
};

class SolutionBetter {
public:
    struct LNode {
        ListNode* ptr;
        bool operator<(const LNode& rhs) const {
            return ptr->val > rhs.ptr->val;
        }
    };

    priority_queue<LNode> pq;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto& node : lists) {
            if (node) pq.push({node});
        }
        ListNode* dummy_head = new ListNode();
        ListNode* prev = dummy_head;
        while (!pq.empty()) {
            auto node = pq.top();
            prev->next = node.ptr;
            prev = node;
            if (node.ptr->next) pq.push({node.ptr->next});
        }
        return dummy_head->next;
    }
};

#endif //LEETCODE_TEST_23_H
