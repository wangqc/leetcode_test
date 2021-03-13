//
// Created by 王秋城 on 2021/3/12.
//

#ifndef LEETCODE_TEST_331_H
#define LEETCODE_TEST_331_H

#include "common.h"

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int> sk;
        sk.push(1);
        for (int i = 0; i < preorder.size(); ++i) {
            if (sk.empty()) {
                return false;
            }
            if (preorder[i] == ',') {
                continue;
            }
            if (preorder[i] == '#') {
                sk.top()--;
                if (sk.top() == 0) {
                    sk.pop();
                }
            } else {
                while (i + 1 < preorder.size() && preorder[i+1] != ',') {
                    i++;
                }
                sk.top()--;
                if (sk.top() == 0) {
                    sk.pop();
                }
                sk.push(2);
            }
        }
        return sk.empty();
    }
};

#endif //LEETCODE_TEST_331_H
