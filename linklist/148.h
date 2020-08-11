//
// Created by wangqiucheng on 2020/8/3.
//

#ifndef LEETCODE_TEST_148_H
#define LEETCODE_TEST_148_H

#include "common.h"

class Solution {
public:
    ListNode* mergeTwoSortedLists(ListNode* left, ListNode* right) {
        ListNode* dummy_head = new ListNode(0);
        ListNode* traver = dummy_head;
        while (left && right) {
            if (left->val <= right->val) {
                traver->next = left;
                left = left->next;
            } else {
                traver->next = right;
                right = right->next;
            }
            traver = traver->next;
        }
        if (left) {
            traver->next = left;
        }
        if (right) {
            traver->next = right;
        }
        return dummy_head->next;
    }

    // 双指针法最好是快的指针直接是head->next
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* quick = head->next;
        while (quick && quick->next) {
            slow = slow->next;
            quick = quick->next->next;
        }
        return slow;
    }

    ListNode* mergeSort(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* middle = findMiddle(head);
        ListNode* left_head = head;
        ListNode* right_head = middle->next;
        middle->next = nullptr;
        ListNode* sort_left_head = mergeSort(left_head);
        ListNode* sort_right_head = mergeSort(right_head);
        return mergeTwoSortedLists(sort_left_head, sort_right_head);
    }

    // 这个是递归方法, 严格来说, 这个方法的空间复杂度是O(nlogn), 不是O(1)的空间复杂度
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};

#endif //LEETCODE_TEST_148_H
