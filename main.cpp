#include <iostream>
#include "back_trace/47.h"

using namespace std;

int main() {
    Solution s;
    vector<int> nums{1,32,3,2,1,3,3,1,23,4};
    vector<vector<int>> ret = s.permuteUnique(nums);
    for (auto& v : ret) {
        for (auto& e : v) {
            cout << e << ",";
        }
        cout << endl;
    }
    return 0;
}
