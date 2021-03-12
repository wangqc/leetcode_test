#include "tree/538.h"

int main() {
    vector<string> v({"4", "null", "10"});
    TreeNode* root = build_tree(v);
    print(root);
    Solution s;
    s.convertBST(root);
    print(root);
    return 0;

}
