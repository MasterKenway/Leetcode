//
// Created by Kenway on 3/29/2021.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (k == 0 || !head || !head->next) return head;
        ListNode *p = head;
        int n = 1;
        while (p->next) {
            p = p->next;
            n++;
        }

        int tail = n - k % n;
        if (tail == n) return head;
        p->next = head;
        while (tail--) p = p->next;
        ListNode *res = p->next;
        p->next = nullptr;
        return res;
    }
};