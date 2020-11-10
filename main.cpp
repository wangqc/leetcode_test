#include <iostream>
#include "array/31.h"

using namespace std;

void print(vector<int>& nums) {
    for (auto &e : nums) {
        cout << e << ",";
    }
    cout << endl;
}

int main() {
    Solution S;
    vector<int> n1{1,1,1,2,3,4,5};
    for (int i = 0; i < 8; i++) {
        print(n1);
        S.nextPermutation(n1);
    }
    cout << endl;
    return 0;
}
