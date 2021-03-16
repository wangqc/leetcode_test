//
// Created by 王秋城 on 2021/3/16.
//

#ifndef LEETCODE_TEST_10_H
#define LEETCODE_TEST_10_H

#include "../common.h"

class Solution {
public:
    unordered_map<int, int> mp;
    int fib(int n) {
        mp[0] = 0;
        mp[1] = 1;
        return f(n);
    }

private:
    int f(int n) {
        if (mp.find(n) != mp.end()) {
            return mp[n];
        }
        int ret = (f(n-1) + f(n-2)) % 1000000007;
        mp[n] = ret;
        return ret;
    }
};

#endif //LEETCODE_TEST_10_H
