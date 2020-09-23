//
// Created by 王秋城 on 2020/9/23.
//

#ifndef LEETCODE_TEST_278_H
#define LEETCODE_TEST_278_H

class Solution {
public:
    int firstBadVersion(int n) {
        int mid, start = 0, end = n;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (isBadVersion(mid)) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (isBadVersion(start)) {
            return start;
        }
        return end;
    }
};

#endif //LEETCODE_TEST_278_H
