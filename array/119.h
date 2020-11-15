//
// Created by 王秋城 on 2020/11/11.
//

#ifndef LEETCODE_TEST_119_H
#define LEETCODE_TEST_119_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) {
            return vector<int>();
        }
        vector<int> ret(rowIndex);
        ret[0] = 1;
        for (int i = 1; i < rowIndex; ++i) {
            int prev = 0;
            for (int j = 0; j < i; ++j) {
                int cur = prev + ret[j];
                prev = ret[j];
                ret[j] = cur;
            }
            ret[i] = 1;
        }
        return ret;
    }
};

#endif //LEETCODE_TEST_119_H
