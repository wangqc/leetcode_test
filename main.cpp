#include <iostream>
#include "array/88.h"

using namespace std;

int main() {
    Solution S;
    vector<int> n1{1,2,3,0,0,0};
    vector<int> n2{2,5,6};
    S.merge(n1, 3, n2, 1);
    for (auto e : n1) {
        cout << e << ",";
    }
    cout << endl;
    return 0;
}
