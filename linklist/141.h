//
// Created by wangqiucheng on 2020/7/8.
//

#ifndef LEETCODE_TEST_141_H
#define LEETCODE_TEST_141_H
#include "../common.h"

class Solution {
public:
    // 判断是否有环, 典型的快慢指针遍历
    bool hasCycleV1(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* slow = head->next;
        ListNode* quick = head->next->next;
        while (slow && quick) {
            if (slow == quick) {
                return true;
            }
            if (quick->next == nullptr) {
                return false;
            }
            slow = slow->next;
            quick = quick->next->next;
        }
        return false;
    }

    bool hasCycle(ListNode* head) {
        ListNode* traver_node = head;
        std::unordered_set<ListNode*> has_traver_nodes;
        while (traver_node) {
            if (has_traver_nodes.find(traver_node) != has_traver_nodes.end()) {
                return true;
            }
            has_traver_nodes.insert(traver_node);
            traver_node = traver_node->next;
        }
        return false;
    }
};

#endif //LEETCODE_TEST_141_H
