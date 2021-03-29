//
// Created by Kenway on 3/18/2021.
//
#include <stack>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        std::stack<ListNode *> stack;
        ListNode *p = head, *pre = p, *begin, *end;
        int i = 1;

        while (i <= right) {
            if (i >= left) {
                stack.push(p);
            }

            if (i + 1 == left) {
                p = begin
            }
            p = p->next;
            i++
        }

        end = p;

        if (!stack.empty()) {
            begin->next = p;
            p = stack.top();
            stack.pop();
            while (!stack.empty()) {
                p->next = stack.top();
                stack.pop();
                p = p->next;
            }
            p->next = end;
        }

        return head;
    }
};