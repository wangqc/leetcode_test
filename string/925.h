//
// Created by 王秋城 on 2020/10/22.
//

#ifndef LEETCODE_TEST_925_H
#define LEETCODE_TEST_925_H
#include <string>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int size1 = name.size();
        int size2 = typed.size();
        int idx1 = 0, idx2 = 0;
        while (idx1 < size1 && idx2 < size2) {
            if (name[idx1] == typed[idx2]) {
                idx1++;
                idx2++;
            } else {
                if (idx2 > 0 && typed[idx2] == typed[idx2-1]) {
                    idx2++;
                } else {
                    return false;
                }
            }
        }
        if (idx1 < size1) {
            return false;
        }
        while (idx2 < size2) {
            if (idx2 > 0 && typed[idx2] == typed[idx2-1]) {
                idx2++;
            } else {
                return false;
            }
        }
        return true;

    }
};

#endif //LEETCODE_TEST_925_H
