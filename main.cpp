#include <iostream>
#include "linklist/206.h"

using namespace std;

int main() {
    ListNode* l = new ListNode(1);
    ListNode* tmp_l = l;
    for (int i = 2; i <= 5; ++i) {
        tmp_l->next = new ListNode(i);
        tmp_l = tmp_l->next;
    }
    tmp_l = l;
    while (tmp_l != nullptr) {
        cout << "before" << tmp_l->val << endl;
        tmp_l = tmp_l->next;
    }

    Solution s;
    ListNode *r_l = s.reverseList(l);
    while (r_l != nullptr) {
        cout << "after" << r_l->val << endl;
        r_l = r_l->next;
    }

    return 0;
}
