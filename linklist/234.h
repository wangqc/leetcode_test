//
// Created by wangqiucheng on 2020/8/11.
//

#ifndef LEETCODE_TEST_234_H
#define LEETCODE_TEST_234_H

#include "common.h"
#include <stack>

class Solution {
public:
    // 错误解法, 忽略了奇数的链表长度, 中间那个可以不管的
    bool isPalindromeError(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        std::stack<int> stk;
        while (head) {
            if (stk.empty()) {
                stk.push(head->val);
            } else if (stk.top() == head->val){
                stk.pop();
            } else {
                stk.push(head->val);
            }
            head = head->next;
        }
        return stk.empty();
    }


    bool isPalindromeV1(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        std::stack<ListNode*> stk;
        ListNode* slow = head, *quick = head->next;
        while (quick && quick->next) {
            stk.push(slow);
            slow = slow->next;
            quick = quick->next->next;
        }
        if (quick) {
            stk.push(slow);
        }
        slow = slow->next;
        while (slow) {
            if (stk.top()->val != slow->val) {
                return false;
            }
            slow = slow->next;
            stk.pop();
        }
        return true;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = nullptr, *cur = head, *tmp_node;
        while (cur) {
            tmp_node = cur->next;
            cur->next = new_head;
            new_head = cur;
            cur = tmp_node;
        }
        return new_head;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }
        ListNode* slow = head, *quick = head->next;
        while (quick && quick->next) {
            slow = slow->next;
            quick = quick->next->next;
        }
        ListNode* second_head = slow->next;
        slow->next = nullptr;
        ListNode* reverse_second_head = reverseList(second_head);

        while(head && reverse_second_head) {
            if (head->val != reverse_second_head->val) {
                return false;
            }
            head = head->next;
            reverse_second_head = reverse_second_head->next;
        }
        return true;
    }
};

#endif //LEETCODE_TEST_234_H
