//
// Created by 王秋城 on 2020/11/7.
//

#ifndef LEETCODE_TEST_58_H
#define LEETCODE_TEST_58_H

#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = 0;
        bool start_count = false;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (!start_count) {
                    continue;
                } else {
                    return size;
                }
            } else {
                start_count = true;
                size++;
            }
        }
        return size;
    }
};

#endif //LEETCODE_TEST_58_H
