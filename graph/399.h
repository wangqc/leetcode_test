//
// Created by 王秋城 on 2021/3/2.
//

#ifndef LEETCODE_TEST_399_H
#define LEETCODE_TEST_399_H

#include "../common.h"

class Solution {
public:
    vector<double>
    calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, map<string, double>> graph;
        for (int i = 0; i < equations.size(); ++i) {
            auto& neight = graph[equations[i][0]];
            neight[equations[i][1]] = values[i];

            auto& verse_neight = graph[equations[i][1]];
            verse_neight[equations[i][0]] = 1/values[i];
        }

        vector<double> ret(queries.size(), 1.0);
        for (int i = 0; i < queries.size(); ++i) {
            if (graph.find(queries[i][0]) == graph.end() || graph.find(queries[i][1]) == graph.end()) {
                ret[i] = -1;
            } else if (queries[i][0] == queries[i][1]) {
                ret[i] = 1;
            } else {
                ret[i] = bfs(graph, queries[i][0], queries[i][1]);
            }
        }
        return ret;
    }

private:
    double bfs(map<string, map<string, double>>& graph, const std::string& source, const std::string& dest) {
        queue<string> qu;
        map<string, double> mp;
        qu.push(source);
        mp[source] = 1.0;
        while(!qu.empty()) {
            int size = qu.size();
            for (int i = 0; i < size; ++i) {
                string s = qu.front();
                if (graph.find(s) == graph.end()) {
                    return -1;
                }
                if (graph[s].find(dest) != graph[s].end()) {
                    return mp[s] * graph[s][dest];
                }
                for (auto& kv : graph[s]) {
                    if (mp.find(kv.first) != mp.end()) {
                        continue;
                    }
                    qu.push(kv.first);
                    mp[kv.first] = kv.second * mp[s];
                }
                qu.pop();
            }
        }
        return -1;
    }
};

#endif //LEETCODE_TEST_399_H
