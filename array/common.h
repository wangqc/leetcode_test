//
// Created by 王秋城 on 2021/1/23.
//

#ifndef LEETCODE_TEST_COMMON_H
#define LEETCODE_TEST_COMMON_H

#include <vector>
#include <iostream>

using namespace std;

void print(const vector<int>& nums) {
    for (auto& n : nums) {
        cout << n << ",";
    }
    cout << endl;
}

void print(vector<int>&& nums) {
    print(nums);
}

void print2rd(const vector<vector<int>>& nums) {
    for (auto& vec : nums) {
        print(vec);
    }
}

void print2rd(vector<vector<int>>&& nums) {
    print2rd(nums);
}

#endif //LEETCODE_TEST_COMMON_H
