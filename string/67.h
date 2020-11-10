//
// Created by 王秋城 on 2020/11/10.
//

#ifndef LEETCODE_TEST_67_H
#define LEETCODE_TEST_67_H

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        stack<char> ch_stk;
        bool add_more = false;
        int i, j;
        for (i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; i--, j--) {
            if (a[i] != b[j]) {
                ch_stk.push(add_more ? '0' : '1');
            } else {
                if (a[i] == '0') {
                    ch_stk.push(add_more ? '1' : '0');
                    add_more = false;
                } else {
                    ch_stk.push(add_more ? '1' : '0');
                    add_more = true;
                }
            }
        }
        for (; i >= 0; i--) {
            if (a[i] == '0') {
                ch_stk.push(add_more ? '1' : '0');
                add_more = false;
            } else {
                ch_stk.push(add_more ? '0' : '1');
            }
        }
        for (; j >= 0; j--) {
            if (b[j] == '0') {
                ch_stk.push(add_more ? '1' : '0');
                add_more = false;
            } else {
                ch_stk.push(add_more ? '0' : '1');
            }
        }
        if (add_more) {
            ch_stk.push('1');
        }
        string ret;
        while(!ch_stk.empty()) {
            ret += ch_stk.top();
            ch_stk.pop();
        }
        return ret;
    }
};

#endif //LEETCODE_TEST_67_H
