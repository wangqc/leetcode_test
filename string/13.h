//
// Created by 王秋城 on 2020/11/5.
//

#ifndef LEETCODE_TEST_13_H
#define LEETCODE_TEST_13_H

#include <string>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> char_mp{
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };
        map<string, int> str_mp{
                {"IV", 4},
                {"IX", 9},
                {"XL", 40},
                {"XC", 90},
                {"CD", 500},
                {"CM", 900}
        };
        map<char, set<char>> mp_st{
                {'I', {'V', 'X'}},
                {'X', {'L', 'C'}},
                {'C', {'D', 'M'}}
        };
        int ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (mp_st.find(s[i]) == mp_st.end() || i + 1 == s.size() ||
                mp_st[s[i]].find(s[i + 1]) == mp_st[s[i]].end()) {
                ret += char_mp[s[i]];
            } else {
                string str(2, s[i]);
                str[1] = s[++i];
                ret += str_mp[str];
            }
        }
        return ret;
    }
};

#endif //LEETCODE_TEST_13_H
