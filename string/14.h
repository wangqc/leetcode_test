//
// Created by 王秋城 on 2020/11/6.
//

#ifndef LEETCODE_TEST_14_H
#define LEETCODE_TEST_14_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret;
        if (strs.empty()) {
            return ret;
        }
        ret = strs[0];
        int common_len = ret.size();
        for (int i = 1; i < strs.size(); ++i) {
            int j;
            for (j = 0; j < common_len && j < strs[i].size(); ++j) {
                if (ret[j] != strs[i][j]) {
                    break;
                }
            }
            if (j == 0) {
                return "";
            }
            common_len = std::min(common_len, j);
        }
        return ret.substr(0, common_len);
    }
};

#endif //LEETCODE_TEST_14_H
