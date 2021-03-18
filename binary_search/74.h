//
// Created by wangqiucheng on 2020/9/23.
//

#ifndef LEETCODE_TEST_74_H
#define LEETCODE_TEST_74_H

#include "../common.h"

using namespace std;

class Solution {
public:
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int mid, start = 0, end = row * col - 1;
        while (start <= end) {
            mid = start + (end - start) / 2;
            int r = mid / col;
            int c = mid - r * col;
            if (matrix[r][c] == target) {
                return true;
            }
            if (target < matrix[r][c]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int r, c, mid, begin = 0, end = row*col;
        while (begin < end) {
            mid = begin + ((end - begin) >> 1);
            r = mid / col;
            c = mid - r*col;
            if (matrix[r][c] < target) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        if (begin >= row*col) {
            return false;
        }
        r = begin / col;
        c = begin - r * col;
        return (matrix[r][c] == target);
    }

};

#endif //LEETCODE_TEST_74_H
