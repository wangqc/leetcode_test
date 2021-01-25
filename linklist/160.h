//
// Created by 王秋城 on 2021/1/25.
//

#ifndef LEETCODE_TEST_160_H
#define LEETCODE_TEST_160_H

#include "../common.h"

class Solution {
public:
    // https://leetcode-cn.com/problems/intersection-of-two-linked-lists/submissions/
    // 最简单想到的是哈希法。 不过可以考虑重走对方走过的路来找到相交点
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cur_a = headA;
        ListNode* cur_b = headB;
        while (1) {
            if (cur_a == cur_b) {
                return cur_a;
            }
            if (!cur_a) {
                cur_a = headB;
            } else {
                cur_a = cur_a->next;
            }
            if (!cur_b) {
                cur_b = headA;
            } else {
                cur_b = cur_b->next;
            }
        }
        return nullptr;
    }

private:

};
#endif //LEETCODE_TEST_160_H
