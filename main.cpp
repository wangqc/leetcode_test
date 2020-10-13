#include <iostream>
#include "linklist/24.h"

using namespace std;

int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    for (int i = 2; i < 11; ++i) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    cur = head;
    while (cur) {
        cout << cur->val << ",";
        cur = cur->next;
    }
    cout << endl;
    ListNode* swap_head = s.swapPairsV3(head);
    while (swap_head) {
        cout << swap_head->val << ",";
        swap_head = swap_head->next;
    }
    cout << endl;
    return 0;
}
