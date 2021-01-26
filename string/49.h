//
// Created by 王秋城 on 2021/1/26.
//

#ifndef LEETCODE_TEST_49_H
#define LEETCODE_TEST_49_H

#include "../common.h"

class Solution {
public:
    // https://leetcode-cn.com/problems/group-anagrams/submissions/
    // 简单的哈希查找即可
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto& s : strs) {
            string tmp_s = s;
            sort(tmp_s.begin(), tmp_s.end());
            auto& mp_v = mp[tmp_s];
            mp_v.push_back(s);
        }
        vector<vector<string>> ret;
        for (auto& kv : mp) {
            ret.push_back(kv.second);
        }
        return ret;
    }
};

#endif //LEETCODE_TEST_49_H
