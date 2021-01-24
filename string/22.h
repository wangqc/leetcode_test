//
// Created by 王秋城 on 2021/1/23.
//

#ifndef LEETCODE_TEST_22_H
#define LEETCODE_TEST_22_H

#include "../common.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return vector<string>();
        }
        vector<string> parens;
        string cur_str = "";
        generate(parens, cur_str, 0, 0, n);
        return parens;
    }

private:
    void generate(vector<string>& parens, string& cur_str, int left, int right, const int n) {
        if (cur_str.size() == n*2) {
            parens.push_back(cur_str);
            return;
        }
        if (left < n) {
            cur_str.push_back('(');
            generate(parens, cur_str, left + 1, right, n);
            cur_str.pop_back();
        }
        if (right < left) {
            cur_str.push_back(')');
            generate(parens, cur_str, left, right + 1, n);
            cur_str.pop_back();
        }
    }
};

#endif //LEETCODE_TEST_22_H
