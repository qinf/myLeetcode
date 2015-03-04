#ifndef _STRUCT_H
#define _STRUCT_H
#include <iostream>
using std::cout;
using std::endl;
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
#endif
