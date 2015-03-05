#include "Struct.h"
using namespace std;
ListNode *reverseList(ListNode *L) {
    ListNode dummy(-1);
    ListNode *p = &dummy;
    while (L != nullptr) {
        ListNode *tmp = L->next;
        L->next = p->next;
        p->next = L;
        L = tmp;
    }
    return dummy.next;
}
void reorderList(ListNode *head) {
    if (head == nullptr)
        return ;
    int count = 0;
    ListNode *tmp = head;
    while (tmp != nullptr) {
        ++count;
        tmp = tmp->next;
    }
    int n =  (count % 2 == 0) ? (count / 2)  : (count / 2 + 1);
    ListNode *node = nullptr;
    for (int i = 0; i < n; ++i) {
        if (i == 0)
            node = head;
        else
            node = node->next;
    }
    node = node->next;
    node = reverseList(node);
    ListNode *L = head;
    while (node != nullptr) {
        ListNode *tmp = node->next;
        node->next = L->next;
        L->next = node;
        L = L->next->next;
        node = tmp;
    }
    L->next = nullptr;
}
int main() {
    int A[] = {1, 2, 3, 4, 5};
    ListNode *l = build(A, 5);
    reorderList(l);
    print(l);
}
