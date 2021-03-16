#include "sword/04.h"

int main() {
    vector<vector<int>> v;
    v.push_back({1,4,7,11,15});
    v.push_back({2,5,8,12,19});
    v.push_back({3,6,9,16,22});
    v.push_back({10,13,14,17,24});
    v.push_back({18,21,23,26,30});
    Solution s;
    cout << s.findNumberIn2DArray(v, 20) << endl;
    return 0;

}
