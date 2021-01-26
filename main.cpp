#include "back_trace/79.h"

#include "common.h"

int main() {
    Solution S;
    vector<vector<char>> nums{{'A', 'B', 'C', 'E'},
                              {'S', 'F', 'C', 'S'},
                              {'A', 'D', 'E', 'E'}};
    string s = "ABFSADECCESE";
    print(S.exist(nums, s));
    return 0;
}
