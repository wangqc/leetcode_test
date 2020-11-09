//
// Created by 王秋城 on 2020/11/7.
//

#ifndef LEETCODE_TEST_53_H
#define LEETCODE_TEST_53_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> f(nums.size(), nums[0]);
        int max = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            f[i] = std::max(f[i-1] + nums[i], nums[i]);
            max = std::max(max, f[i]);
        }
        return max;
    }

    int maxSubArrayV2(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int pre = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            pre = std::max(pre + nums[i], nums[i]);
            max = std::max(max, pre);
        }
        return max;
    }

    // https://leetcode-cn.com/problems/maximum-subarray/solution/zui-da-zi-xu-he-by-leetcode-solution/
    struct Status {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    };

    Status get(vector<int> &a, int l, int r) {
        if (l == r) {
            return (Status) {a[l], a[l], a[l], a[l]};
        }
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        return pushUp(lSub, rSub);
    }

    // 线段树版本
    int maxSubArrayV3(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};

#endif //LEETCODE_TEST_53_H
