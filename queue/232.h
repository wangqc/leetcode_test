//
// Created by wangqiucheng on 2020/9/11.
//

#ifndef LEETCODE_TEST_232_H
#define LEETCODE_TEST_232_H

#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        push_stk.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = peek();
        pop_stk.pop();
        return top;
    }

    /** Get the front element. */
    int peek() {
        int top;
        if (pop_stk.empty()) {
            while (!push_stk.empty()) {
                pop_stk.push(push_stk.top());
                push_stk.pop();
            }
        }
        top = pop_stk.top();
        return top;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return (push_stk.empty() && pop_stk.empty());
    }

private:
    stack<int> push_stk;
    stack<int> pop_stk;
};

#endif //LEETCODE_TEST_232_H
