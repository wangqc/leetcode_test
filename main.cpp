#include "binary_search/209.h"

int main() {
    vector<int> v({2,3,1,2,4,3});
    for (auto riter = v.rbegin(); riter != v.rend(); ++riter) {
        cout << *riter << endl;
    }
    return 0;
}
