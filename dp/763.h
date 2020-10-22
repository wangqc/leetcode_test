//
// Created by 王秋城 on 2020/10/22.
//

#ifndef LEETCODE_TEST_763_H
#define LEETCODE_TEST_763_H

#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ret;
        map<char, int> mp;
        int size = S.size();
        for (int i = 0; i < size; ++i) {
            mp[S[i]] = i;
        }
        int last_split_end = -1, split_end = 0;
        for (int i = 0; i < size; ++i) {
            int cur_most_right_pos = mp[S[i]];
            if (cur_most_right_pos == i) {
                if (split_end == i) {
                    ret.push_back(split_end - last_split_end);
                    last_split_end = split_end;
                    split_end++;
                }
            } else {
                if (cur_most_right_pos > split_end) {
                    split_end = cur_most_right_pos;
                }
            }
        }
        return ret;
    }
};

#endif //LEETCODE_TEST_763_H
