//
// Created by 王秋城 on 2020/10/22.
//

#ifndef LEETCODE_TEST_6_H
#define LEETCODE_TEST_6_H

#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if (numRows == 1) {
            return s;
        }
        if (numRows == 2) {
            string s1, s2;
            for (int i = 0; i < size; i+=2) {
                s1 += s[i];
            }
            for (int i = 1; i < size; i+= 2) {
                s2 += s[i];
            }
            return s1 + s2;
        }
        string ret_s;
        ret_s += s[0];
        for (int j = 2; ; j += 2) {
            int try_idx = j * numRows - j;
            if (try_idx >= size) {
                break;
            }
            ret_s += s[try_idx];
        }
        for (int i = 1; i < numRows - 1; ++i) {
            if (i < size) {
                ret_s += s[i];
            }
            for (int j = 2; ; j+=2) {
                int try_idx = j * numRows - j - i;
                if (try_idx >= size) {
                    break;
                }
                ret_s += s[try_idx];
                try_idx = j * numRows - j + i;
                if (try_idx >= size) {
                    break;
                }
                ret_s += s[try_idx];
            }
        }
        if (numRows - 1 < size) {
            ret_s += s[numRows - 1];
        }
        for (int j = 3; ; j+=2) {
            int try_idx = j * numRows - j;
            if (try_idx >= size) {
                break;
            }
            ret_s += s[try_idx];
        }
        return ret_s;
    }
};

#endif //LEETCODE_TEST_6_H
