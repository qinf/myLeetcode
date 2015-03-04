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
ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode *p = head, *prev;
    ListNode node(-1);
    for (int i = 1; i <= n; ++i) {
        if (i < m) {
            if (node.next == nullptr)
                node.next = p;
            else {
                p = p->next;
            }
            continue;
        }
        prev = p;
        if (i > m && i <= n) {
            prev->next = p->next;
            p->next = p->next->next;
            prev->next->next = p;
        }
    }
    return node.next;
}
int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    ListNode *L = build(A, 7);
    L = reverseBetween(L, 1, 7);
    print(L);
    return 0;
}
