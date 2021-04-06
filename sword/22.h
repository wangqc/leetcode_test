//
// Created by 王秋城 on 2021/4/6.
//

#ifndef LEETCODE_TEST_22_H
#define LEETCODE_TEST_22_H

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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* quick = head;
        while (k && quick) {
            k--;
            quick = quick->next;
        }
        if (k != 0) {
            return nullptr;
        }
        ListNode* slow = head;
        while (quick) {
            slow = slow->next;
            quick = quick->next;
        }
        return slow;
    }
};

#endif //LEETCODE_TEST_22_H
