#include "binary_search/240.h"

#include "common.h"

int main() {
    Solution S;
    vector<vector<int>> v{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    cout << S.searchMatrix(v, 16) << endl;
    return 0;
}
