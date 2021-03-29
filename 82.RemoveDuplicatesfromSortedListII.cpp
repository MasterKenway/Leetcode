//
// Created by Kenway on 3/25/2021.
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *p = head, *q, *pre;
        while (p) {
            if (p->next && p->val == p->next->val) {
                q = p;
                while (q->next && q->val == q->next->val) {
                    q = q->next;
                }

                if (p == head) {
                    head = q->next;
                    p = q->next;
                } else {
                    pre->next = q->next;
                    p = q->next;
                }
            } else {
                pre = p;
                p = p->next;
            }
        }

        return head;
    }
};