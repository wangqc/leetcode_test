//
// Created by 王秋城 on 2020/9/19.
//

#ifndef LEETCODE_TEST_260_H
#define LEETCODE_TEST_260_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bitmask = 0;
        for (auto& n : nums) {
            bitmask ^= n;
        }

        int diff  = bitmask & (-bitmask);
        int x = 0;
        for (auto& n : nums) {
            if ((n & diff) != 0) {
                x ^= n;
            }
        }
        int y = bitmask ^ x;
        return vector<int>{x, y};
    }
};

#endif //LEETCODE_TEST_260_H
