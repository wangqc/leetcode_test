//
// Created by wangqiucheng on 2020/8/1.
//

#ifndef LEETCODE_TEST_82_H
#define LEETCODE_TEST_82_H

#include "../common.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy_node = new ListNode(0);
        dummy_node->next = head;
        ListNode* cur_node = dummy_node;
        while (cur_node->next && cur_node->next->next) {
            if (cur_node->next->val != cur_node->next->next->val) {
                cur_node = cur_node->next;
            } else {
                int equal_val = cur_node->next->val;
                ListNode* traval_node = cur_node->next->next->next;
                while (traval_node) {
                    if (traval_node->val == equal_val) {
                        traval_node = traval_node->next;
                    } else {
                        break;
                    }
                }
                cur_node->next = traval_node;
            }
        }
        return dummy_node->next;
    }
};

#endif //LEETCODE_TEST_82_H
