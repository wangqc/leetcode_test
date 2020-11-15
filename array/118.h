//
// Created by 王秋城 on 2020/11/11.
//

#ifndef LEETCODE_TEST_118_H
#define LEETCODE_TEST_118_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) {
            return vector<vector<int>>();
        }
        vector<vector<int>> ret;
        vector<int> row(1, 1);
        ret.push_back(row);
        for (int i = 1; i < numRows; ++i) {
            vector<int> row(1, 1);
            for (int j = 1; j < i; ++j) {
                row.push_back(ret[i-1][j] + ret[i-1][j-1]);
            }
            row.push_back(1);
            ret.push_back(row);
        }
        return ret;
    }
};

#endif //LEETCODE_TEST_118_H
