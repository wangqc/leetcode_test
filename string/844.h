//
// Created by wangqiucheng on 2020/10/19.
//

#ifndef LEETCODE_TEST_844_H
#define LEETCODE_TEST_844_H

#include <string>

using namespace std;

class Solution {
public:
    void back_walk_and_mark(string& str) {
        int size = str.size();
        int cur_back_char_size = 0;
        for (int i = size - 1; i >= 0; i--) {
            if (str[i] == '#') {
                cur_back_char_size++;
            } else if (cur_back_char_size > 0) {
                str[i] = '0';
                cur_back_char_size--;
            }
        }
    }

    bool backspaceCompare(string S, string T) {
        back_walk_and_mark(S);
        back_walk_and_mark(T);
        int s_size = S.size(), t_size = T.size(), i, j;
        for (i = 0, j = 0; i < s_size && j < t_size;) {
            if (S[i] == '#' || S[i] == '0') {
                i++;
                continue;
            }
            if (T[j] == '#' || T[j] == '0') {
                j++;
                continue;
            }
            if (S[i] != T[j]) {
                return false;
            }
            i++;
            j++;
        }
        while (i < s_size) {
            if (S[i] != '#' && S[i] != '0') {
                return false;
            }
            i++;
        }
        while (j < t_size) {
            if (T[j] != '#' && T[j] != '0') {
                return false;
            }
            j++;
        }
        return true;
    }

    bool backspaceCompareV2(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (S[i] == '#') {
                    skipS++, i--;
                } else if (skipS > 0) {
                    skipS--, i--;
                } else {
                    break;
                }
            }
            while (j >= 0) {
                if (T[j] == '#') {
                    skipT++, j--;
                } else if (skipT > 0) {
                    skipT--, j--;
                } else {
                    break;
                }
            }
            if (i >= 0 && j >= 0) {
                if (S[i] != T[j]) {
                    return false;
                }
            } else {
                if (i >= 0 || j >= 0) {
                    return false;
                }
            }
            i--, j--;
        }
        return true;
    }
};

#endif //LEETCODE_TEST_844_H
