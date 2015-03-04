#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) { }
};
ListNode *build(int A[], int n) {
    ListNode *L = nullptr, *p = nullptr;
    //ListNode *node = nullptr;
    for(int i = 0; i < n; ++i) {
        ListNode *node = new ListNode(A[i]);
        if (L == nullptr) {
            L = p = node;
        } else {
            p->next = node;
            p = p->next;
        }
    }
    return L;
}
void print(ListNode *L) {
    ListNode *p = L;
    while(p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}
ListNode *swapPairs(ListNode *head) {
    if (head == nullptr)
        return nullptr;
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *p = head, *tmp = &dummy;
    ListNode *q = p->next == nullptr ? nullptr : p->next;
    while(q != nullptr) {
        tmp->next = q;
        p->next = q->next;
        q->next = p;
        tmp = p;
        p = p->next;
        if (p == nullptr) {
            q = nullptr;
        } else {
            q = p->next;
        }
    }
    return dummy.next;
}
int main() {
    int A[] = {};
    ListNode *L = build(A, 0);
    L = swapPairs(L);
    print(L);
    return 0;
}
