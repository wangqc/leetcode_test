//
// Created by 王秋城 on 2021/3/19.
//

#ifndef LEETCODE_TEST_209_H
#define LEETCODE_TEST_209_H

#include "../common.h"


// 经典的前缀和+二分查找
/*
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> sum(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            sum[i+1] = sum[i] + nums[i];
        }
        int ret = INT_MAX;
        for (int i = 0; i < sum.size(); ++i) {
            int new_target = target + sum[i];
            auto bound = lower_bound(sum.begin(), sum.end(), new_target);
            if (bound != sum.end()) {
                ret = min(ret, static_cast<int>(bound - sum.begin()) - i);
            }
        }
        return ret == INT_MAX ? 0 : ret;
    }
};
*/


// 双指针滑动窗口
// 右指针不断往右移，移动到不能往右移动为止(具体条件根据题目而定)。当右指针到最右边以后，开始挪动左指针，释放窗口左边界。
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int size = nums.size();
        int end = 0, start = 0;
        int sum = 0;
        int ret = INT_MAX;
        while (end < size) {
            sum += nums[end];
            while (sum >= target) {
                ret = min(ret, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return (ret == INT_MAX) ? 0 : ret;
    }
};

#endif //LEETCODE_TEST_209_H
