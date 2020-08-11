#include <iostream>
#include "linklist/234.h"

using namespace std;

void print(ListNode* l) {
    if (l == nullptr) {
        cout << "nullptr" << endl;
    }
    while(l) {
        cout << l->val << ",";
        l = l->next;
    }
    cout << endl;
}

int main() {
    Solution s;
    auto head = new ListNode(1);
    auto l1 = new ListNode(2);
    auto l2 = new ListNode(3);
    auto l3 = new ListNode(3);
    auto l4 = new ListNode(2);
    auto l5 = new ListNode(1);

    head->next = l1;
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;


    print(head);
    cout << s.isPalindrome(head) << endl;

    return 0;
}
