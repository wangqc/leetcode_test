//
// Created by wangqiucheng on 2020/10/17.
//

#ifndef LEETCODE_TEST_977_H
#define LEETCODE_TEST_977_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> negative_vec;
        vector<int> postive_vec;
        int size = A.size();
        for (int i = 0; i < size; ++i) {
            if (A[i] < 0) {
                negative_vec.push_back(A[i]*A[i]);
            } else {
                postive_vec.push_back(A[i]*A[i]);
            }
        }
        vector<int> ret_vec;
        int i, j;
        for (i = negative_vec.size() - 1, j = 0; i >= 0 && j < postive_vec.size();) {
            if (negative_vec[i] < postive_vec[j]) {
                ret_vec.push_back(negative_vec[i--]);
            } else {
                ret_vec.push_back(postive_vec[j++]);
            }
        }
        while (i >= 0) {
            ret_vec.push_back(negative_vec[i--]);
        }
        while (j < postive_vec.size()) {
            ret_vec.push_back(postive_vec[j++]);
        }
        return ret_vec;
    }
};


#endif //LEETCODE_TEST_977_H
