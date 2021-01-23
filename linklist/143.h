//
// Created by wangqiucheng on 2020/8/11.
//

#ifndef LEETCODE_TEST_143_H
#define LEETCODE_TEST_143_H

#include "../common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // 比较蠢的的做法
    void reorderListStupid(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        std::stack<ListNode*> prev_half_node;
        ListNode* slow = head, *quick = head->next;
        while (quick && quick->next) {
            prev_half_node.push(slow);
            slow = slow->next;
            quick = quick->next->next;
        }

        ListNode* new_head = slow;
        ListNode* ahead_node = slow->next;
        if (quick) {
            slow = ahead_node;
            ahead_node = ahead_node->next;
            slow->next = nullptr;
        } else {
            slow->next = nullptr;
        }
        while (ahead_node) {
            slow = ahead_node;
            ahead_node = ahead_node->next;
            slow->next = new_head;
            new_head = slow;
            ListNode* prev_node = prev_half_node.top();
            prev_node->next = new_head;
            new_head = prev_node;
            prev_half_node.pop();
        }
        *head = *new_head;
        return;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = nullptr, *cur = head, *prev_node;
        while (cur) {
            prev_node = cur->next;
            cur->next = new_head;
            new_head = cur;
            cur = prev_node;
        }
        return new_head;
    }

    void mergeTwoList(ListNode* left, ListNode* right) {
        ListNode* left_tmp, *right_tmp;
        while (right) {
            left_tmp = left->next;
            right_tmp = right->next;
            left->next = right;
            right->next = left_tmp;
            left = left_tmp;
            right = right_tmp;
        }
        return;
    }

    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        ListNode* slow = head, *quick = head->next;
        while (quick && quick->next) {
            slow = slow->next;
            quick = quick->next->next;
        }
        ListNode* back_head = slow->next;
        slow->next = nullptr;
        ListNode* reverse_back_head = reverseList(back_head);
        return mergeTwoList(head, reverse_back_head);
    }
};

#endif //LEETCODE_TEST_143_H
