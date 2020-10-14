#include <iostream>
#include "string/1002.h"

using namespace std;

int main() {
    Solution s;
    vector<string> v;

    vector<string> ret = s.commonChars(v);
    for (auto& str : ret) {
        cout << str << endl;
    }
    return 0;
}
