//
// Created by Kenway on 3/5/2021.
//
#include <stack>

class MyQueue {
public:
    std::stack<int> stack;
    std::stack<int> stack2;

    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top;
        if (!stack2.empty()) {
            top = stack2.top();
            stack2.pop();
        } else {
            while (!stack.empty()) {
                stack2.push(stack.top());
                stack.pop();
            }

            top = stack2.top();
            stack2.pop();
        }

        return top;
    }

    /** Get the front element. */
    int peek() {
        if (!stack2.empty()) {
            return stack2.top();
        } else {
            while (!stack.empty()) {
                stack2.push(stack.top());
                stack.pop();
            }

            return stack2.top();
        }
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stack2.empty() && stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */