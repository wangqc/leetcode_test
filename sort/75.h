//
// Created by 王秋城 on 2020/10/7.
//

#ifndef LEETCODE_TEST_75_H
#define LEETCODE_TEST_75_H

#include <vector>

using namespace std;

// 三向切分快排， 牛皮
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pivot = 1;
        int lt = -1;
        int gt = nums.size();
        int eq = 0;
        while (eq < gt) {
            if (nums[eq] < pivot) {
                lt++;
                swap(nums[eq], nums[lt]);
                eq++;
            } else if (nums[eq] == pivot) {
                eq++;
            } else {
                gt--;
                swap(nums[eq], nums[gt]);
            }
        }
    }
};

// 桶排序，也是66的
class SolutionBucket {
public:
    void sortColors(vector<int>& nums) {
        int zero_num = 0, one_num = 0;
        for (auto& n : nums) {
            if (n == 0) zero_num++;
            if (n == 1) one_num++;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (zero_num > 0) {
                nums[i] = 0;
                zero_num--;
            } else if (one_num > 0) {
                nums[i] = 1;
                one_num--;
            } else {
                nums[i] = 2;
            }
        }
    }
};
#endif //LEETCODE_TEST_75_H
