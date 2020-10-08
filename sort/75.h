//
// Created by 王秋城 on 2020/10/7.
//

#ifndef LEETCODE_TEST_75_H
#define LEETCODE_TEST_75_H

#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) zero++;
            if (nums[i] == 1) one++;
            if (nums[i] == 2) two++;
        }
        int idx = 0;
        for (int i = 0; i < zero; ++i) {
            nums[idx++] = 0;
        }
        for (int i = 0; i < one; ++i) {
            nums[idx++] = 1;
        }
        for (int i = 0; i < two; ++i) {
            nums[idx++] = 2;
        }
    }


    // TODO:一趟遍历
    void sortColorsV2(vector<int>& nums) {
        int sort_start_idx = 0, sort_end_idx = nums.size() - 1;
        for (int i = 0; i < nums.size();) {

        }
    }
};

#endif //LEETCODE_TEST_75_H
