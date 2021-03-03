//
// Created by 王秋城 on 2021/3/3.
//

#ifndef LEETCODE_TEST_406_H
#define LEETCODE_TEST_406_H

#include "../common.h"

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
        });
        vector<vector<int>> ans;
        for (const vector<int>& person: people) {
            ans.insert(ans.begin() + person[1], person);
        }
        return ans;
    }
};

#endif //LEETCODE_TEST_406_H
