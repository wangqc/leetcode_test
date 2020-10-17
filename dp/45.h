//
// Created by 王秋城 on 2020/10/2.
//

#ifndef LEETCODE_TEST_45_H
#define LEETCODE_TEST_45_H

#include <vector>

using namespace std;

class Solution {
public:
    // 从前往后
    int jump(vector<int>& nums) {
        int cur_max_pos = 0, total_max_pos = 0, size = nums.size(), step = 0;
        for (int i = 0; i < size - 1; ++i) {
            cur_max_pos = max(cur_max_pos, i + nums[i]);
            // 在上一次最远到达之前，都是在一步之内，然后再更新下次最远
            if (i >= total_max_pos) {
                total_max_pos = cur_max_pos;
                step++;
            }
        }
        return step;
    }

    // 从后往前
    // 如果是全1的话， 容易超出时间限制
    int jumpV2(vector<int>& nums) {
        int step = 0, pos = nums.size() - 1;
        while (pos != 0) {
            for (int i = 0; i < pos; i++) {
                if (i + nums[i] >= pos) {
                    pos = i;
                    step++;
                    break;
                }
            }
        }
        return step;
    }
};

#endif //LEETCODE_TEST_45_H
