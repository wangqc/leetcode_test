//
// Created by wangqiucheng on 2020/7/4.
//

#ifndef LEETCODE_TEST_206_H
#define LEETCODE_TEST_206_H
#include "common.h"

class Solution {
public:
    // 递归V1版本
    ListNode* reverseList_digui_1(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* reverse_head = reverseList_digui_1(head->next);
        head->next = nullptr;
        ListNode* trasver_head = reverse_head;
        while (trasver_head->next != nullptr) {
            trasver_head = trasver_head->next;
        }
        trasver_head->next = head;
        return  reverse_head;
    }

    // 迭代版本V1版本
    ListNode* reverseList_diedai_1(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* traver_head = head->next;
        ListNode* new_head = head;
        new_head->next = nullptr;
        while (traver_head != nullptr) {
            ListNode* tmp_node = traver_head->next;
            traver_head->next = new_head;
            new_head = traver_head;
            traver_head = tmp_node;
        }
        return new_head;
    }

    // 递归最终版本
    // 改进：要记得不管head的next节点怎么变, head的next节点还是指着它, 最后将head放在next->next即可
    ListNode* reverseList_digui(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *new_head = reverseList_digui(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
    }
};
#endif //LEETCODE_TEST_206_H
