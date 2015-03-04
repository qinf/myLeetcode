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
ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (n == 1 && head->next == nullptr) {
        delete head;
        head = nullptr;
        return head;
    }
    ListNode *p1 = nullptr, *p2 = nullptr;
    for(int i = 0; i < n; ++i) {
        if (i == 0)
            p1 = head;
        else
            p1 = p1->next;
    }
    if (p1->next == nullptr) {
        head = head->next;
        return head;
    }
    while(p1->next != nullptr) {
        p1 = p1->next;
        if (p2 == nullptr)
            p2 = head;
        else
            p2 = p2->next;
    }
    p2->next = p2->next->next;
    return head;
}
ListNode *removeNthFromEnd2(ListNode *head, int n) {
    //ListNode dummy{-1, head};
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *p = &dummy, *q = &dummy;
    for (int i = 0; i < n; ++i) {
        p = p->next;
    }
    while(p->next) {
        p = p->next;
        q = q->next;
    }
    ListNode *tmp = q->next;
    q->next = tmp->next;
    delete tmp;
    tmp = nullptr;
    return dummy.next;
}
int main() {
    int A[] = {1, 2, 3, 4};
    ListNode *L = build(A, 4);
    L = removeNthFromEnd2(L, 4);
    print(L);
    return 0;
}
