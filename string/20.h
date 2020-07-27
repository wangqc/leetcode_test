//
// Created by wangqiucheng on 2020/7/24.
//

#ifndef LEETCODE_TEST_20_H
#define LEETCODE_TEST_20_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for (auto ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                v.push_back(ch);
            } else {
                if (v.empty()) {
                    return false;
                }
                if (ch == ')') {
                    if (v.back() != '(') {
                        return false;
                    } else {
                        v.pop_back();
                    }
                }
                if (ch == '}') {
                    if (v.back() != '{') {
                        return false;
                    } else {
                        v.pop_back();
                    }
                }
                if (ch == ']') {
                    if (v.back() != '[') {
                        return false;
                    } else {
                        v.pop_back();
                    }
                }
            }
        }
        return v.empty();
    }
};

#endif //LEETCODE_TEST_20_H
