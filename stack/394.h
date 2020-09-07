//
// Created by wangqiucheng on 2020/9/1.
//

#ifndef LEETCODE_TEST_394_H
#define LEETCODE_TEST_394_H

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        std::string cur_str = "";
        int num = 0;
        std::stack<std::string> str_stk;
        std::stack<int> int_stk;
        for (auto &c : s) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                cur_str += c;
            } else if (c >= '0' && c <= '9') {
                num = 10 * num + (c - '0');
            } else if (c == '[') {
                str_stk.push(cur_str);
                int_stk.push(num);
                cur_str = "";
                num = 0;
            } else {
                int multi = int_stk.top();
                int_stk.pop();
                std::string multi_str = "";
                for (int i = 0; i < multi; ++i) {
                    multi_str += cur_str;
                }
                cur_str = str_stk.top() + multi_str;
                str_stk.pop();
            }
        }
        return cur_str;
    }
};

#endif //LEETCODE_TEST_394_H
