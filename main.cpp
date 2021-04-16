#include "dfs/90.h"

int main() {
    Solution s;
    vector<int> v({1,2,2,3});
    auto ret = s.subsetsWithDup(v);
    for (auto& vec : ret) {
        for (auto& e : vec) {
            cout << e << ",";
        }
        cout << endl;
    }
    return 0;
}
