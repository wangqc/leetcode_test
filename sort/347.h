//
// Created by 王秋城 on 2021/5/7.
//

#ifndef LEETCODE_TEST_247_H
#define LEETCODE_TEST_247_H

#include "../common.h"

class MyCompare {
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const {
        return lhs.second > rhs.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> appear_times;
        for (auto& n : nums) {
            appear_times[n]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare> pq;
        for (auto& kv : appear_times) {
            pq.emplace({kv.first, kv.second});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ret;
        while (!pq.empty()) {
            ret.emplace_back(pq.top().first);
            pq.pop();
        }
        return ret;
    }
};

#endif //LEETCODE_TEST_247_H
