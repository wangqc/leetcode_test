#include "binary_search/34.h"

int main() {
    Solution S;
    vector<int> nums{1,1,1,1,6,6,6,6,6};
    int target = 6;
    print(S.searchRange(nums, target));
    return 0;
}
