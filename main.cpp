#include "dfs/78.h"

int main() {
    SolutionTwo s;
    vector<int> v({1,2,3});
    auto ret = s.subsets(v);
    for (auto& vec : ret) {
        for (auto& e : vec) {
            cout << e << ",";
        }
        cout << endl;
    }
    return 0;
}
