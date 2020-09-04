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
        string ret;
        stack<string> prev_str_stk;
        stack<int> dup_num;
        int num = 0;
        string str;
        bool prev_is_not_num = true;
        for (auto& c : s) {
            if (c >= '0' and c <= '9') {
                if (prev_is_not_num) {
                    prev_str_stk.push(str);
                    prev_is_not_num = false;
                }
                num = 10 * num + (c - '0');
            } else if (c == '[') {
                dup_num.push(num);
                prev_is_not_num = true;
                num = 0;
            } else if (c == ']') {
                int repeated_num = dup_num.top();
                dup_num.pop();
                std::string ss = "";
                for (long long i = 0; i < repeated_num; ++i) {
                    ss += str;
                }
                str = prev_str_stk.top() + ss;
                prev_str_stk.pop();
            } else {
                str += c;
            }
        }
        return str;
    }
};

#endif //LEETCODE_TEST_394_H
