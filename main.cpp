#include "string/139.h"

#include "common.h"

int main() {
    Solution S;
    string s = "appleappleappletoo";
    vector<string> v{"leet", "apple", "too", "leet", "code"};
    cout << S.wordBreak(s, v) << endl;
    return 0;
}
