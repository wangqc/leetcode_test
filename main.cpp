#include "dfs/784.h"

int main() {
    Solution s;
    vector<string> ret = s.letterCasePermutation("3abc");
    for (auto& s : ret) {
        cout << s << endl;
    }
    return 0;
}
