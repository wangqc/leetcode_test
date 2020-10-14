//
// Created by 王秋城 on 2020/10/14.
//

#ifndef LEETCODE_TEST_1002_H
#define LEETCODE_TEST_1002_H

#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> v;
        map<char, int> ch_map;
        for (auto& ch : A[0]) {
            if (ch_map.find(ch) == ch_map.end()) {
                ch_map[ch] = 1;
            } else {
                ch_map[ch]++;
            }
        }

        for (int i = 1; i < A.size(); ++i) {
            map<char, int> cur_ch_map;
            for (auto& ch : A[i]) {
                if (ch_map.find(ch) == ch_map.end()) {
                    continue;
                } else if (cur_ch_map.find(ch) == cur_ch_map.end()) {
                    cur_ch_map[ch] = 1;
                } else {
                    cur_ch_map[ch]++;
                }
            }
            for (auto &kv : cur_ch_map) {
                cur_ch_map[kv.first] = min(kv.second, ch_map[kv.first]);
            }
            ch_map.swap(cur_ch_map);
            if (ch_map.empty()) {
                break;
            }
        }
        for (auto &kv : ch_map) {
            for (int i = 0; i < kv.second; ++i) {
                v.push_back(string(1, kv.first));
            }
        }
        return v;
    }
};

#endif //LEETCODE_TEST_1002_H
