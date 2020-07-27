//
// Created by wangqiucheng on 2020/7/24.
//

#ifndef LEETCODE_TEST_4_H
#define LEETCODE_TEST_4_H

#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> total_nums(size1 + size2);

        int step1 = 0, step2 = 0;
        int idx = 0;
        while (step1 < size1 && step2 < size2) {
            if (nums1[step1] < nums2[step2]) {
                total_nums[idx++] = nums1[step1++];
            } else {
                total_nums[idx++] = nums2[step2++];
            }
        }
        while (step1 < size1) {
            total_nums[idx++] = nums1[step1++];
        }
        while (step2 < size2) {
            total_nums[idx++] = nums2[step2++];
        }
        double res;
        if (idx % 2 == 0) {
            res = (total_nums[idx/2-1] + total_nums[idx/2]) /2.0;
        } else {
            res = total_nums[idx/2];
        }
        return res;
    }
};

#endif //LEETCODE_TEST_4_H
