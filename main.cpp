#include "dp/221.h"

#include "common.h"

int main() {
    Solution S;
    vector<vector<char>> v{{'0','1','0','1','1','1'},{'0','1','0','1','1','1'},{'0','1','0','1','1','1'}};
    vector<vector<char>> v2{{'0', '1'}, {'1','0'}};
    cout << S.maximalSquare(v) << endl;
    return 0;
}
