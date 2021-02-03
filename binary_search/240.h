//
// Created by 王秋城 on 2021/2/1.
//

#ifndef LEETCODE_TEST_240_H
#define LEETCODE_TEST_240_H

#include "../common.h"

// 二种方法：
// 1. 逐行二分
// 3. 右上角寻找
class SolutionStupid {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < col; ++i) {
            int up = 0, down = row - 1;
            while (up <= down) {
                int mid = up + ((down - up) >> 1);
                if (matrix[mid][i] == target) {
                    return true;
                } else if (matrix[mid][i] > target) {
                    down = mid - 1;
                } else {
                    up = mid + 1;
                }
            }
        }
        return false;
    }
};


class SolutionTravel {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int cur_row = 0, cur_col = col - 1;
        int val = matrix[cur_row][cur_col];
        while (val != target) {
            if (val > target) {
                cur_col--;
                if (cur_col < 0) {
                    return false;
                }
            } else if (val < target) {
                cur_row++;
                if (cur_row >= row) {
                    return false;
                }
            }
            val = matrix[cur_row][cur_col];
        }
        return true;
    }
};


#endif //LEETCODE_TEST_240_H
