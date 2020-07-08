#include <iostream>
#include "linklist/876.h"

using namespace std;

void printListNode(ListNode* l) {
    while(l) {
        cout << l->val << ",";
        l = l->next;
    }
    cout << endl;
}

int main() {
    ListNode* l2 = new ListNode(3);
    ListNode* tmp_l = l2;
    for (int i = 10; i < 18; ++i) {
        tmp_l->next = new ListNode(i);
        tmp_l = tmp_l->next;
    }
    printListNode(l2);

    Solution s;
    ListNode* l3 = s.middleNode(l2);
    printListNode(l3);

    return 0;
}
