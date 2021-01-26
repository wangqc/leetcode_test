#include "array/56.h"

#include "common.h"

int main() {
    Solution S;
    vector<vector<int>> nums{{1,4},{0,2},{3,5}, {1,3}, {4,32}, {-3,-1}, {0,1}};
    print(S.merge(nums));
    return 0;
}
