//
// Created by wangqiucheng on 2020/10/28.
//

#ifndef LEETCODE_TEST_1207_H
#define LEETCODE_TEST_1207_H

#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> ele_cnt;
        for (auto& ele : arr) {
            if (ele_cnt.find(ele) == ele_cnt.end()) {
                ele_cnt[ele] = 1;
            } else {
                ele_cnt[ele]++;
            }
        }

        set<int> cnt_set;
        for (auto& kv : ele_cnt) {
            if (cnt_set.find(kv.second) != cnt_set.end()) {
                return false;
            }
            cnt_set.insert(kv.second);
        }
        return true;
    }
};

#endif //LEETCODE_TEST_1207_H
