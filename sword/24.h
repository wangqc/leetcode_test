//
// Created by 王秋城 on 2021/4/6.
//

#ifndef LEETCODE_TEST_24_H
#define LEETCODE_TEST_24_H

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || head->next == nullptr) {
            return head;
        }
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }
};


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
    ListNode* reverseList(ListNode* head) {
        if (!head)  return head;
        ListNode* new_head = head;
        ListNode* next = head->next;
        while (next) {
            ListNode* next_next = next->next;
            next->next = new_head;
            new_head = next;
            next = next_next;
        }
        head->next = nullptr;
        return new_head;
    }
};

#endif //LEETCODE_TEST_24_H
