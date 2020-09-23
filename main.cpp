#include <iostream>
#include "binary_search/35.h"

using namespace std;

int main() {
    Solution s;
    vector<int> v{1,3,5,6};
    int ret = s.searchInsert(v, 7);
    cout << ret << endl;
    return 0;
}
