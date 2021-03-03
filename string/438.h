//
// Created by 王秋城 on 2021/3/3.
//

#ifndef LEETCODE_TEST_438_H
#define LEETCODE_TEST_438_H

#include "../common.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        map<char, int> p_mp;
        for (auto& c : p) {
            p_mp[c]++;
        }
        int p_size = p.size();

        map<char, int> s_mp;
        for (int i = 0; i < p_size; ++i) {
            s_mp[s[i]]++;
        }
        int s_size = s.size();
        for (int i = 0; i < s_size - p_size + 1;) {
            if (cmp(p_mp, s_mp)) {
                res.push_back(i);
            }
            s_mp[s[i]]--;
            s_mp[s[i+p_size]]++;
            i++;
        }
        return res;
    }

    bool cmp(map<char, int>& p_mp, map<char, int>& s_mp) {
        for (auto& kv : p_mp) {
            if (s_mp.find(kv.first) == s_mp.end() || s_mp[kv.first] != kv.second) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODE_TEST_438_H
