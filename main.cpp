#include "dfs/39.h"


int main() {
    SolutionTwo s;
    vector<int> v({2,3,6,7});
    auto ret = s.combinationSum(v, 7);
    for (auto& vec : ret) {
        for (auto& e : vec) {
            cout << e << ",";
        }
        cout << endl;
    }
    return 0;
}
