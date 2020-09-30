#include <iostream>
#include "binary_search/81.h"

using namespace std;

int main() {
    Solution s;
    vector<int> v{1,1,1,1,1,1,1,1,1,3,1,1,1};
    for (int i = 0; i < 5; ++i) {
        cout << i << ":" << s.search(v, i) << endl;
    }
    return 0;
}
