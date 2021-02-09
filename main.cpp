#include "dp/719.h"

#include "common.h"

int main() {
    SolutionGreedy S;
    vector<int> v{1,3,2,8,4,9};
    cout << S.maxProfit(v, 2) << endl;
    return 0;
}
