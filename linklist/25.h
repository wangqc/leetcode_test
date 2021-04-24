//
// Created by 王秋城 on 2021/4/24.
//

#ifndef LEETCODE_TEST_25_H
#define LEETCODE_TEST_25_H

#include "../common.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        ListNode* cur = head;
        int cnt = 0;
        while (cur) {
            cur = cur->next;
            cnt++;
        }
        if (k >= cnt) {
            return reverseList(head);
        }
        ListNode* dummy_head = new ListNode();
        dummy_head->next = head;
        ListNode* prev_tail = dummy_head;
        ListNode* cur_head = head;
        ListNode* cur_node = head;
        int cur_num = 0;
        while (cur_node) {
            cur_num++;
            if (cur_num == k) {
                ListNode* cur_next = cur_node->next;
                cur_node->next = nullptr;
                prev_tail->next = reverseList(cur_head);
                prev_tail = cur_head;
                cur_head->next = cur_next;
                cur_node = cur_next;
                cur_head = cur_next;
                cur_num = 0;
            } else {
                cur_node = cur_node->next;
            }
        }
        return dummy_head->next;
    }
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
        }
        return new_head;
    }
};

#endif //LEETCODE_TEST_25_H
