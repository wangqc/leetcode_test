#include <iostream>
#include "linklist/86.h"

using namespace std;

void print(ListNode* l) {
    while(l) {
        cout << l->val << ",";
        l = l->next;
    }
    cout << endl;
}

int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    ListNode* l = head;
    l->next = new ListNode(4);
    l = l->next;
    l->next = new ListNode(3);
    l = l->next;
    l->next = new ListNode(2);
    l = l->next;
    l->next = new ListNode(5);
    l = l->next;
    l->next = new ListNode(2);


    print(head);
    print(s.partition(head, 4));

    return 0;
}
