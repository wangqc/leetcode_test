#include "dp/304.h"

#include "common.h"

int main() {
    vector<vector<int>> v{{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
    NumMatrix n(v);
    cout << n.sumRegion(2,1,4,3) << endl;
    cout << n.sumRegion(1,1,2,2) << endl;
    cout << n.sumRegion(1,2,2,4) << endl;

    return 0;
}
