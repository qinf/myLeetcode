#include "Struct.h"
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode dummy(-1);
    ListNode *head = &dummy;
    while (l1 && l2) {
        if (l1->val > l2->val) {
            head->next = l2;
            head = head->next;
            l2 = l2->next;
        } else {
            head->next = l1;
            head = head->next;
            l1 = l1->next;
        }
    }
    while (l1) {
        head->next = l1;
        head = head->next;
        l1 = l1->next;
    }
    while (l2) {
        head->next = l2;
        head = head->next;
        l2 = l2->next;
    }
    return dummy.next;
}
int main() {
    int A[] = {1, 4, 5, 7};
    int B[] = {2, 3, 6};
    ListNode *l1 = build(A, 4);
    ListNode *l2 = build(B, 0);
    ListNode *L = mergeTwoLists(l1, l2);
    print(L);
    return 0;
}
