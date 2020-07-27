#include <iostream>
#include "string/20.h"

using namespace std;


int main() {
    Solution s;
    string str;

    str = "";
    cout << s.isValid(str) << endl;

    str = "{}";
    cout << s.isValid(str) << endl;

    str = "(]";
    cout << s.isValid(str) << endl;

    str = "{[]}";
    cout << s.isValid(str) << endl;
    return 0;
}
