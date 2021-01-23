//
// Created by 王秋城 on 2020/10/13.
//

#ifndef LEETCODE_TEST_24_H
#define LEETCODE_TEST_24_H

#include "../common.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *odd_list = head, *even_list = head->next;
        ListNode *odd_cur = odd_list, *even_cur = even_list;
        ListNode *cur = head->next;
        while (cur) {
            odd_cur->next = cur->next;
            odd_cur = odd_cur->next;
            cur = cur->next;
            if (!cur) {
                even_cur->next = nullptr;
                break;
            } else {
                even_cur->next = cur->next;
                even_cur = even_cur->next;
            }
            cur = cur->next;
        }
        odd_cur = odd_list;
        even_cur = even_list;
        ListNode* prev_last_node = nullptr;
        while (even_cur) {
            ListNode* even_tmp = even_cur->next;
            even_cur->next = odd_cur;
            ListNode* odd_tmp = odd_cur->next;
            odd_cur->next = even_tmp;
            prev_last_node = odd_cur;
            even_cur = even_tmp;
            odd_cur = odd_tmp;
        }
        if (odd_cur) {
            prev_last_node->next = odd_cur;
        }
        return even_list;
    }

    // 递归还是简单啊
    ListNode* swapPairsV2(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = head->next;
        head->next = swapPairsV2(newHead->next);
        newHead->next = head;
        return newHead;
    }

    ListNode* swapPairsV3(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* dummy_node = new ListNode(0);
        dummy_node->next = head;
        ListNode* travel = dummy_node;
        while (travel->next && travel->next->next) {
            ListNode* odd_node = travel->next;
            ListNode* even_node = travel->next->next;
            ListNode* next_odd_node = travel->next->next->next;
            travel->next = even_node;
            travel->next->next = odd_node;
            travel->next->next->next = next_odd_node;
            travel = travel->next->next;
        }
        return dummy_node->next;
    }
};


#endif //LEETCODE_TEST_24_H
