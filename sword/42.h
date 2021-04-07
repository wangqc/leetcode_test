//
// Created by 王秋城 on 2021/4/7.
//

#ifndef LEETCODE_TEST_42_H
#define LEETCODE_TEST_42_H

// 分治需要维护左右状态
class Solution {
public:
    struct Status {
        int lSum, rSum, mSum, iSum;
    };

    Status push_up(Status& l, Status& r) {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, l.rSum + r.iSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return Status({lSum, rSum, mSum, iSum});
    }

    Status get(vector<int>&nums, int l, int r) {
        if (l == r) {
            return Status({nums[l], nums[l], nums[l], nums[l]});
        }
        int m = l + ((r-l)>>1);
        Status lSub = get(nums, l, m);
        Status rSub = get(nums, m+1, r);
        return push_up(lSub, rSub);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};

// 最经典还是使用dp

#endif //LEETCODE_TEST_42_H
