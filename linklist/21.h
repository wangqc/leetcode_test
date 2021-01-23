//
// Created by wangqiucheng on 2020/7/8.
//

#ifndef LEETCODE_TEST_21_H
#define LEETCODE_TEST_21_H
#include "../common.h"

class Solution {
public:
    // 迭代版本, 太容易想到了, 最好还是加个哨兵在前面
    ListNode* mergeTwoListsIter(ListNode* l1, ListNode* l2) {
        ListNode* new_head = new ListNode(0);
        ListNode* step_node = new_head;
        while(l1 && l2) {
            if (l1->val < l2->val) {
                step_node->next = l1;
                l1 = l1->next;
            } else {
                step_node->next = l2;
                l2 = l2->next;
            }
            step_node = step_node->next;
        }
        if (l1) {
            step_node->next = l1;
        }
        if (l2) {
            step_node->next = l2;
        }
        return new_head->next;
    }


    // 合并递归版本, 也是reall简洁了
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

#endif //LEETCODE_TEST_21_H
