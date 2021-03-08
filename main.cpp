#include "dp/494.h"
#include "common.h"

int main() {
    SolutionGood s;
    Solution s2;
    SolutionBetter s3;
    vector<int> v({0,0,0,0,0,1});
    print(s.findTargetSumWays(v, 1));
    print(s2.findTargetSumWays(v, 1));
    print(s3.findTargetSumWays(v, 1));
    return 0;

}
