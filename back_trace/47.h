//
// Created by 王秋城 on 2020/9/18.
//

#ifndef LEETCODE_TEST_47_H
#define LEETCODE_TEST_47_H

#include <vector>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    void back_trace(const vector<int>& nums, vector<vector<int>>& ret, vector<int>& vec, vector<int>& vis) {
        if (vec.size() == nums.size()) {
            ret.emplace_back(vec);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            // 最关键的一步， 排序后然后保证重复的都是从左到右依次加入就行
            if (vis[i] == 1 || (i > 0 && nums[i] == nums[i-1] && vis[i-1] == 0)) {
                continue;
            }
            vis[i] = 1;
            vec.emplace_back(nums[i]);
            back_trace(nums, ret, vec, vis);
            vec.pop_back();
            vis[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty()) {
            return vector<vector<int>>();
        }
        vector<vector<int>> ret;
        vector<int> vec;
        vector<int> vis(nums.size(), 0);
        sort(nums.begin(), nums.end());
        back_trace(nums, ret, vec, vis);
        return ret;
    }
};

#endif //LEETCODE_TEST_47_H
