//
// Created by 王秋城 on 2021/1/26.
//

#ifndef LEETCODE_TEST_56_H
#define LEETCODE_TEST_56_H

#include "../common.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
        vector<vector<int>> ret;
        int size = intervals.size();
        for (int i = 0; i < size;) {
            vector<int> tmp;
            tmp.push_back(intervals[i][0]);
            tmp.push_back(intervals[i][1]);
            bool has_push = false;
            int j = 1;
            for (; j < size - i; ++j) {
                if (tmp[1] < intervals[i + j][0]) {
                    ret.push_back(tmp);
                    has_push = true;
                    break;
                } else if (tmp[1] < intervals[i+j][1]) {
                    tmp[1] = intervals[i+j][1];
                }
            }
            if (!has_push) {
                ret.push_back(tmp);
            }
            i += j;
        }
        return ret;
    }
};

#endif //LEETCODE_TEST_56_H
