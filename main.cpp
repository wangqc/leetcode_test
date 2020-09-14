#include <iostream>
#include "queue/542.h"

using namespace std;

int main() {
    Solution s;
    vector<vector<int>> matrics{
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}};
    vector<vector<int>> ret = s.updateMatrixV2(matrics);
    for (auto& v : ret) {
        for (auto& e : v) {
            cout << e << ",";
        }
        cout << endl;
    }
    return 0;
}
