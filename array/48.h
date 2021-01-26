//
// Created by 王秋城 on 2021/1/26.
//

#ifndef LEETCODE_TEST_48_H
#define LEETCODE_TEST_48_H

#include "../common.h"

class Solution {
public:
    //https://leetcode-cn.com/problems/rotate-image/
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int rotate_circle = size / 2;
        for (int c = 0; c < rotate_circle; ++c) {
            int rotate_side_end = size - c;
            for (int i = c; i < rotate_side_end - 1; ++i) {
                int left_up = matrix[c][i];
                int right_up = matrix[i][size - 1 - c];
                int right_down = matrix[size - 1 - c][size - 1 - i];
                int left_down = matrix[size - 1 - i][c];

                matrix[c][i] = left_down;
                matrix[i][size - 1 - c] = left_up;
                matrix[size - 1 -c][size-1-i] = right_up;
                matrix[size-1-i][c] = right_down;
            }
        }
    }
};

#endif //LEETCODE_TEST_48_H
