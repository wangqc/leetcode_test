//
// Created by 王秋城 on 2020/11/10.
//

#ifndef LEETCODE_TEST_88_H
#define LEETCODE_TEST_88_H

#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        }
        int index = m + n - 1;
        int i, j;
        for (i = m - 1, j = n - 1; i >= 0 && j >=0;) {
            if (nums1[i] > nums2[j]) {
                nums1[index] = nums1[i];
                i--;
            } else {
                nums1[index] = nums2[j];
                j--;
            }
            index--;
        }
        while (j >= 0) {
            nums1[index--] = nums2[j--];
        }
        return;
    }
};

#endif //LEETCODE_TEST_88_H
