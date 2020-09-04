//
// Created by wangqiucheng on 2020/9/1.
//

#ifndef LEETCODE_TEST_150_H
#define LEETCODE_TEST_150_H

#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<long long> stk;
        for (auto &token : tokens) {
            if (token != "+" and token != "-" and token != "*" and token != "/") {
                stk.push(std::atoll(token.c_str()));
            } else {
                long long second_num = stk.top();
                stk.pop();
                long long first_num = stk.top();
                stk.pop();
                long long result;
                if (token == "+") {
                    result = first_num + second_num;
                } else if (token == "-") {
                    result = first_num - second_num;
                } else if (token == "*") {
                    result = first_num * second_num;
                } else {
                    result = first_num / second_num;
                }
                stk.push(result);
            }
        }
        return stk.top();
    }
};

#endif //LEETCODE_TEST_150_H
