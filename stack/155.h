//
// Created by wangqiucheng on 2020/8/31.
//

#ifndef LEETCODE_TEST_155_H
#define LEETCODE_TEST_155_H

#include <stack>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        stk.push(x);

        if (min_stk.empty()) {
            min_stk.push(x);
        } else {
            if (min_stk.top() > x) {
                min_stk.push(x);
            } else {
                min_stk.push(min_stk.top());
            }
        }
    }

    void pop() {
        if (stk.empty()) {
            return;
        }
        stk.pop();
        min_stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min_stk.top();
    }

    std::stack<int> stk;
    std::stack<int> min_stk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

#endif //LEETCODE_TEST_155_H
