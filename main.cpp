#include "dfs/79.h"

int main() {
    SolutionTwo s;
    vector<vector<char>> v({{'a','b','c','e'},{'s','f','c','s'},{'a','d','e','e'}});
    cout << s.exist(v, "abcb") << endl;
    return 0;
}
