//
// Created by 王秋城 on 2020/11/10.
//

#ifndef LEETCODE_TEST_66_H
#define LEETCODE_TEST_66_H

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add_more = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int cur_sum = digits[i] + add_more;
            digits[i] = cur_sum % 10;
            add_more = cur_sum / 10;
            if (add_more == 0) {
                return digits;
            }
        }
        if (add_more == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

#endif //LEETCODE_TEST_66_H
