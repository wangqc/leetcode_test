//
// Created by 王秋城 on 2021/3/16.
//

#ifndef LEETCODE_TEST_04_H
#define LEETCODE_TEST_04_H

#include "../common.h"

// 并不是只要排序好就是二分查找的
class Solution {
public:
    // 这种有点像是二叉排序树
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int row_size = matrix.size(), col_size = matrix[0].size();
        int i = 0, j = col_size - 1;
        while (i < row_size && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};

#endif //LEETCODE_TEST_04_H
