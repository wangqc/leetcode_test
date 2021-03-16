//
// Created by 王秋城 on 2021/3/16.
//

#ifndef LEETCODE_TEST_05_H
#define LEETCODE_TEST_05_H

#include "../common.h"

class Solution {
public:
    string replaceSpace(string s) {
        int black_cnt = 0;
        for (auto& c : s) {
            if (c == ' ') {
                black_cnt++;
            }
        }
        if (black_cnt == 0) {
            return s;
        }
        string ret = s + string(2 * black_cnt, ' ');
        int s_idx = s.size() - 1;
        int r_idx = ret.size() - 1;
        for (int i = s_idx; i >=0; --i) {
            if (r_idx == i) {
                break;
            }
            if (s[i] == ' ') {
                ret[r_idx--] = '0';
                ret[r_idx--] = '2';
                ret[r_idx--] = '%';
            } else {
                ret[r_idx--] = s[i];
            }
        }
        return ret;
    }
};

#endif //LEETCODE_TEST_05_H
