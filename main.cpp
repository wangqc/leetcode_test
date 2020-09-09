#include <iostream>
#include "back_trace/77.h"
#include <string>

using namespace std;

int main() {
    Solution s;
    int n = 4;
    int k = 2;
    vector<vector<int>> ret = s.combine(n, k);
    for (auto& v : ret) {
        for (auto& e : v) {
            cout << e << ",";
        }
        cout << endl;
    }
    return 0;
}
