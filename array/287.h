//
// Created by 王秋城 on 2021/2/4.
//

#ifndef LEETCODE_TEST_287_H
#define LEETCODE_TEST_287_H

#include "../common.h"

class Solution {
public:
    // 最简单粗暴的解
    // 1. 排序
    // 2. set
    // 3. 快慢指针
    int findDuplicateStupid(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) {
                return nums[i];
            }
        }
        return 0;
    }

    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

class SolutionBi {
public:
    int findDuplicate(vector<int> &nums) {
        int len = nums.size();
        int left = 1;
        int right = len - 1;

        while (left < right) {
            int mid = left + (right - left + 1) / 2;

            int cnt = 0;
            for (int num:nums) {
                if (num < mid) {
                    cnt++;
                }
            }

            // 根据抽屉原理，严格小于 4 的数的个数如果大于等于 4 个，
            // 此时重复元素一定出现在 [1, 3] 区间里

            if (cnt >= mid) {
                // 重复的元素一定出现在 [left, mid - 1] 区间里
                right = mid - 1;
            } else {
                // if 分析正确了以后，else 搜索的区间就是 if 的反面
                // [mid, right]
                // 注意：此时需要调整中位数的取法为上取整
                left = mid;
            }
        }
        return left;
    }
};

#endif //LEETCODE_TEST_287_H
