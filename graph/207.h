//
// Created by 王秋城 on 2021/1/28.
//

#ifndef LEETCODE_TEST_207_H
#define LEETCODE_TEST_207_H

#include "../common.h"

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visted;
    bool valid = true;

    void dfs(int u) {
        cout << u << endl;
        visted[u] = 1;
        for (auto i : edges[u]) {
            if (visted[i] == 0) {
                dfs(i);
                if (!valid) {
                    return;
                }
            } else if (visted[i] == 1) {
                valid = false;
                return;
            }
        }
        visted[u] = 2;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visted.resize(numCourses);

        for (auto& dep : prerequisites) {
            edges[dep[1]].push_back(dep[0]);
        }

        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visted[i]) {
                dfs(i);
            }
        }
        return valid;
    }


};

class Solution2 {
public:
    vector<vector<int>> edges;
    vector<int> indeg;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);

        for (auto& dep : prerequisites) {
            edges[dep[1]].push_back(dep[0]);
            ++indeg[dep[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        int visited = 0;
        while (!q.empty()) {
            ++visited;
            int u = q.front();
            q.pop();
            for (int v :edges[u]) {
                --indeg[v];
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        return visited == numCourses;
    }
};
#endif //LEETCODE_TEST_207_H
