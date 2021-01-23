//
// Created by wangqiucheng on 2020/7/8.
//

#ifndef LEETCODE_TEST_19_H
#define LEETCODE_TEST_19_H
#include "../common.h"


class Solution {
public:
    // 最粗暴
    ListNode* removeNthFromEndV1(ListNode* head, int n) {
        ListNode* tmp = head;
        int size = 0;
        while(tmp) {
            size += 1;
            tmp = tmp->next;
        }
        if (n > size) {
            return head;
        }
        if (n == size) {
            return head->next;
        }
        int prev_del_node = size - n;
        tmp = head;
        for (int i = 1; i < prev_del_node; ++i) {
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        return head;
    }

    // 借用哈希表
    ListNode* removeNthFromEndV2(ListNode* head, int n) {
        std::unordered_map<int, ListNode*> idx_node_map;
        ListNode* tmp = head;
        int idx = 0;
        while (tmp) {
            idx += 1;
            idx_node_map[idx] = tmp;
            tmp = tmp->next;
        }
        int prev_del_node_idx = idx - n;
        if (prev_del_node_idx < 0) {
            return head;
        } else if (prev_del_node_idx == 0) {
            return head->next;
        } else {
            idx_node_map[prev_del_node_idx]->next = idx_node_map[prev_del_node_idx]->next->next;
        }
        return head;
    }

    // 还是快慢指针
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* del_node = head;
        for (int i = 0; i < n; ++i) {
            if (del_node != nullptr) {
                del_node = del_node->next;
            } else {
                return head;
            }
        }
        ListNode* prev_head = new ListNode(0);
        prev_head->next = head;
        ListNode* tmp = prev_head;
        while (tmp && del_node) {
            tmp = tmp->next;
            del_node = del_node->next;
        }
        tmp->next = tmp->next->next;
        return prev_head->next;
    }
};
#endif //LEETCODE_TEST_19_H
