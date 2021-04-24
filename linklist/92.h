//
// Created by wangqiucheng on 2020/8/1.
//

#ifndef LEETCODE_TEST_92_H
#define LEETCODE_TEST_92_H

#include "../common.h"

class Solution {
public:
    // 最粗暴的方法, 就是截取成三段, 中间一段进行reverse, 然后再拼接
    ListNode* reverseBetweenV1(ListNode* head, int m, int n) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* dummy_head_node = new ListNode(0);
        dummy_head_node->next = head;

        ListNode* reverse_head = head;
        ListNode* prev_tail = dummy_head_node;
        for (int i = 1; i < m; ++i) {
            reverse_head = reverse_head->next;
            prev_tail = prev_tail->next;
        }

        ListNode* reverse_tail = head;
        ListNode* after_head = head->next;
        for (int i = 1; i < n; ++i) {
            reverse_tail = reverse_tail->next;
            after_head = after_head->next;
        }
        reverse_tail->next = nullptr;

        ListNode* new_reverse_head = reverseList(reverse_head);
        prev_tail->next = new_reverse_head;

        while (new_reverse_head->next) {
            new_reverse_head = new_reverse_head->next;
        }
        new_reverse_head->next = after_head;

        return dummy_head_node->next;
    }

    ListNode* reverseBetweenBefore(ListNode* head, int m, int n) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* dummy_node = new ListNode(0);
        dummy_node->next = head;

        ListNode* m_head = head;
        ListNode* prev_m_tail = dummy_node;
        for (int i = 1; i < m; ++i) {
            m_head = m_head->next;
            prev_m_tail = prev_m_tail->next;
        }
        prev_m_tail->next = reverseList(m_head);

        ListNode* n_head = prev_m_tail->next;
        ListNode* prev_n_tail = prev_m_tail;
        for (int i = 0; i < n - m; ++i) {
            prev_n_tail = prev_n_tail->next;
            n_head = n_head->next;
        }
        prev_n_tail->next = reverseList(n_head);

        return dummy_node->next;
    }


    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next) {
            return head;
        }

    }

private:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }

};

#endif //LEETCODE_TEST_92_H
