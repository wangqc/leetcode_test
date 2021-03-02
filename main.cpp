#include "graph/399.h"

#include "common.h"

int main() {
    vector<vector<string>> v{{"a", "b"},{"b", "c"}, {"bc", "cd"}};
    vector<double> v2{1.5, 2.5, 5.0};
    vector<vector<string>> v3{{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}};

    Solution s;
    print(s.calcEquation(v, v2, v3));

    return 0;
}
