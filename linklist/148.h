//
// Created by wangqiucheng on 2020/8/3.
//

#ifndef LEETCODE_TEST_148_H
#define LEETCODE_TEST_148_H

#include "../common.h"

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

// 自底向上， 节省空间
class SolutionBetter {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        int length = 0;
        ListNode* node = head;
        while (node != nullptr) {
            length++;
            node = node->next;
        }
        ListNode* dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode* prev = dummyHead, *curr = dummyHead->next;
            while (curr != nullptr) {
                ListNode* head1 = curr;
                for (int i = 1; i < subLength && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* head2 = curr->next;
                curr->next = nullptr;
                curr = head2;
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* next = nullptr;
                if (curr != nullptr) {
                    next = curr->next;
                    curr->next = nullptr;
                }
                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                curr = next;
            }
        }
        return dummyHead->next;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};

#endif //LEETCODE_TEST_148_H
