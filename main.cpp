#include "array/215.h"

#include "common.h"

int main() {
    Solution S;
    vector<int> v{3,2,1,34,3,2,2,1,3};
    cout << S.findKthLargest(v, 10) << endl;
    return 0;
}
