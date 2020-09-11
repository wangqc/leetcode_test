#include <iostream>
#include "back_trace/40.h"

using namespace std;

int main() {
    Solution s;
    vector<int> candidates{10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ret = s.combinationSum2(candidates, target);
    for (auto& v : ret) {
        for (auto& e : v) {
            cout << e << ",";
        }
        cout << endl;
    }
    return 0;
}
