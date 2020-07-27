//
// Created by wangqiucheng on 2020/7/27.
//

#ifndef LEETCODE_TEST_28_H
#define LEETCODE_TEST_28_H

#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    // 最暴力的解法
    int strStrV1(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        if (needle.size() > haystack.size()) {
            return -1;
        }

        int i, j;
        for (i = 0; i < haystack.size() - needle.size() + 1; ++i) {
            for (j = 0; j < needle.size(); ++j) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == needle.size()) {
                return i;
            }
        }
        return -1;
    }

    // hash值法
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        if (needle.size() > haystack.size()) {
            return -1;
        }
        int n_size = needle.size();
        int mod = pow(2, 31);
        int multi = 26;

        int needle_hash = 0, haystack_hash = 0, max_multi = 1;
        for (int i = 0; i < n_size; ++i) {
            haystack_hash = (haystack_hash * multi + haystack[i] - 'a') % mod;
            needle_hash = (needle_hash * multi + needle[i] - 'a') % mod;
            max_multi = (max_multi * multi) % mod;
        }
        if (haystack_hash == needle_hash) {
            return 0;
        }

        for (int i = 1; i < haystack.size() - n_size + 1; ++i) {
            haystack_hash =
                    (haystack_hash * multi - (haystack[i - 1]-'a') * max_multi + (haystack[i + n_size - 1]-'a')) % mod;
            if (haystack_hash == needle_hash) {
                return i;
            }
        }
        return -1;
    }
};

#endif //LEETCODE_TEST_28_H
