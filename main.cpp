#include <iostream>
#include "array/119.h"

using namespace std;

void print(vector<int>& nums) {
    for (auto &e : nums) {
        cout << e << ",";
    }
    cout << endl;
}

int main() {
    Solution S;
    for (int i = 1; i <= 10; i++) {
        vector<int> ret = S.getRow(i);
        print(ret);
    }
    cout << endl;
    return 0;
}
