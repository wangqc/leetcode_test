//
// Created by wangqiucheng on 2020/8/1.
//

#ifndef LEETCODE_TEST_86_H
#define LEETCODE_TEST_86_H

#include "common.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* smaller_dummy_node = new ListNode(0);
        ListNode* larger_dummy_node = new ListNode(0);

        smaller_dummy_node->next = head;

        ListNode* smaller_travel_node = smaller_dummy_node;
        ListNode* larger_travel_node = larger_dummy_node;
        while (smaller_travel_node->next) {
            if (smaller_travel_node->next->val >= x) {
                larger_travel_node->next = smaller_travel_node->next;
                smaller_travel_node->next = smaller_travel_node->next->next;
                larger_travel_node->next->next = nullptr;
                larger_travel_node = larger_travel_node->next;
            } else {
                smaller_travel_node = smaller_travel_node->next;
            }
        }
        smaller_travel_node->next = larger_dummy_node->next;
        return smaller_dummy_node->next;
    }
};

#endif //LEETCODE_TEST_86_H
