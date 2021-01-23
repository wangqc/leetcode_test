//
// Created by wangqiucheng on 2020/8/1.
//

#ifndef LEETCODE_TEST_83_H
#define LEETCODE_TEST_83_H

#include "../common.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* l = head;
        while (l->next) {
            if (l->val == l->next->val) {
                l->next = l->next->next;
            } else {
                l = l->next;
            }
        }
        return head;
    }
};

#endif //LEETCODE_TEST_83_H
