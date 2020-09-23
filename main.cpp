#include <iostream>
#include "binary_search/74.h"

using namespace std;

int main() {
    Solution s;
    vector<vector<int>> v{{1,3,5,6}, {7,9,10,12}, {15,19,21,32}, {35,43,46,55}};
    bool ret = s.searchMatrix(v, 55);
    cout << ret << endl;
    return 0;
}
