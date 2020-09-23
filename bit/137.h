//
// Created by 王秋城 on 2020/9/19.
//

#ifndef LEETCODE_TEST_137_H
#define LEETCODE_TEST_137_H

#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    // 比较低效的方法
    int singleNumber(vector<int>& nums) {
        map<int, bool> mp;
        for (auto& n : nums) {
            if (mp.find(n) != mp.end()) {
                mp[n] = false;
            } else {
                mp[n] = true;
            }
        }
        for (auto& kv : mp) {
            if (!kv.second) continue;
            return kv.first;
        }
        return 0;
    }


    int singleNumberV2(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (auto x : nums) {
                cnt += (x>>i)&1;
            }
            res |= (cnt%3)<<i;
        }
        return res;
    }

    // 异或， 永远的神
    // 这个比较容易懂的是使用模电的异或来操作，使用状态转移表
    // 有个tricky的地方就是two的计算是使用了新值one，两者是同构的
    int singleNumberV3(vector<int>& nums) {
        int one = 0, two = 0;
        for (auto& n : nums) {
            one = one ^ n & ~two;
            two = two ^ n & ~one;
        }
        return one;
    }
};

#endif //LEETCODE_TEST_137_H
