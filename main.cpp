#include "dfs/216.h"

int main() {
    SolutionTwo s;
    auto ret = s.combinationSum3(3, 7) ;
    for (auto& vec : ret) {
        for (auto& e : vec) {
            cout << e << ",";
        }
        cout << endl;
    }
    return 0;
}
