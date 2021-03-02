//
// Created by 王秋城 on 2021/2/19.
//

#ifndef LEETCODE_TEST_348_H
#define LEETCODE_TEST_348_H

#include "../common.h"

class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> appear_times;
        for (auto& n : nums) {
            appear_times[n]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pq(cmp);
        for (auto& [num, times] : appear_times) {
            if (pq.size() == k) {
                if (pq.top().second < times) {
                    pq.pop();
                    pq.emplace(num, times);
                }
            } else {
                pq.emplace(num, times);
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

// TODO: 手写堆

#endif //LEETCODE_TEST_348_H
