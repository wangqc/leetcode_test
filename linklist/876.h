//
// Created by wangqiucheng on 2020/7/8.
//

#ifndef LEETCODE_TEST_876_H
#define LEETCODE_TEST_876_H
#include "common.h"
#include <unordered_map>

class Solution {
public:
    // 都提示了结点数在1到100之间了, 直接map开搞就行咯
    ListNode* middleNodeV1(ListNode* head) {
        ListNode* tmp = head;
        std::unordered_map<int, ListNode*> idx_node_map;
        int len = 0;
        while (tmp) {
            idx_node_map[len] = tmp;
            len += 1;
            tmp = tmp->next;
        }
        return idx_node_map[len/2];
    }

    // 傻方法
    ListNode* middleNodeV2(ListNode* head) {
        ListNode* tmp = head;
        int len = 0;
        while (tmp) {
            len += 1;
            tmp = tmp->next;
        }

        tmp = head;
        for (int i = 0; i < len/2; ++i) {
            tmp = tmp->next;
        }
        return tmp;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* quick = head;
        while(quick && quick->next) {
            slow = slow->next;
            quick = quick->next->next;
        }
        return slow;
    }
};


#endif //LEETCODE_TEST_876_H
