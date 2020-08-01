//
// Created by wangqiucheng on 2020/7/27.
//

#ifndef LEETCODE_TEST_78_H
#define LEETCODE_TEST_78_H

#include <vector>

using namespace std;

class Solution {
public:
    // 迭代法
    vector<vector<int>> subsetsV1(vector<int>& nums) {
        vector<vector<int>> ret_vec;
        ret_vec.push_back(vector<int>());
        for (auto n : nums) {
            int size = ret_vec.size();
            for (int i = 0; i < size; ++i) {
                vector<int> tmp_vec(ret_vec[i]);
                tmp_vec.push_back(n);
                ret_vec.push_back(tmp_vec);
            }
        }

        return ret_vec;
    }

    // 回溯法1
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret_vec;
        vector<int> tmp_vec;

        back_track(nums, 0, tmp_vec, ret_vec);
        return ret_vec;
    }

    void back_track(vector<int>& nums, int pos, vector<int> tmp_vec, vector<vector<int>>& ret_vec) {
        ret_vec.push_back(tmp_vec);
        for (int i = pos; i < nums.size(); ++i) {
            tmp_vec.push_back(nums[i]);
            back_track(nums, i + 1, tmp_vec, ret_vec);
            tmp_vec.pop_back();
        }
    }
};

#endif //LEETCODE_TEST_78_H
