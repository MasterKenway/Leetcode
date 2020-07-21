#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1,* q = l2,* l3 = nullptr,* r = nullptr;
        while (p != nullptr && q != nullptr) {

            if (p == l1 && q == l2) {
                r = new ListNode(p->val + q->val);
                l3 = r;
            } else {
                r->next =  new ListNode(p->val + q->val);
                r = r->next;
            }

            p = p->next;
            q = q->next;
        }

        if (p != nullptr && q == nullptr) {
            if (r == nullptr){
                r = p;
                l3 = r;
            }
            else
                r->next = p;
        }

        if (p == nullptr && q != nullptr) {
            if (r == nullptr) {
                r = q;
                l3 = r;
            }
            else
                r->next = q;
        }

        r = l3;
        while (r != nullptr) {
            if (r->val >= 10) {
                r->val = r->val - 10;
                if (r->next != nullptr)
                    r->next->val++;
                else
                    r->next = new ListNode(1);
            }
            r = r->next;
        }

        return l3;
    }
};

/*
int main() {
    Solution solution;
    ListNode* l1 = new ListNode(5);
    */
/*l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);*//*

    //ListNode* l1 = nullptr;
    ListNode* l2 = new ListNode(5);
    */
/*l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);*//*

    ListNode* r = solution.addTwoNumbers(l1 ,l2);
    while (r != nullptr) {
        cout << r->val << " ";
        r = r->next;
    }
}*/
