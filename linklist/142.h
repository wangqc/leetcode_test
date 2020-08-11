//
// Created by wangqiucheng on 2020/8/11.
//

#ifndef LEETCODE_TEST_142_H
#define LEETCODE_TEST_142_H

#include "common.h"
#include <set>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // 最简单的想法
    ListNode *detectCycleSimple(ListNode *head) {
        std::set<ListNode*> node_set;
        while (head) {
            if (node_set.find(head) != node_set.end()) {
                return head;
            }
            node_set.insert(head);
            head = head->next;
        }
        return nullptr;
    }

    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* slow = head, *quick = head->next;
        while(quick && quick->next && quick != slow) {
            slow = slow->next;
            quick = quick->next->next;
        }
        if (quick == nullptr || quick->next == nullptr) {
            return nullptr;
        }
        quick = head;
        while (quick != slow) {
            slow = slow->next;
            quick = quick->next;
        }
        return slow;
    }
};

#endif //LEETCODE_TEST_142_H
