//
// Created by 王秋城 on 2021/1/23.
//

#ifndef LEETCODE_TEST_17_H
#define LEETCODE_TEST_17_H

#include "../common.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return vector<string>();
        }
        vector<string> ret(1, "");
        for (const auto& c : digits) {
            letterCombination(ret, digit_2_alpha.at(c));
        }
        return ret;
    }

private:
    void letterCombination(vector<string>& ret, const vector<string> to_append) {
        vector<string> local;
        for (const auto& s1 : ret) {
            for (const auto& s2 : to_append) {
                local.push_back(s1 + s2);
            }
        }
        ret.swap(local);
    }

    const map<char, vector<string>> digit_2_alpha{{'2', {"a", "b", "c"}},
                                                  {'3', {"d", "e", "f"}},
                                                  {'4', {"g", "h", "i"}},
                                                  {'5', {"j", "k", "l"}},
                                                  {'6', {"m", "n", "o"}},
                                                  {'7', {"p", "q", "r", "s"}},
                                                  {'8', {"t", "u", "v"}},
                                                  {'9', {"w", "x", "y", "z"}}};
};

#endif //LEETCODE_TEST_17_H
