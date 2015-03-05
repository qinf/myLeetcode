#include "Struct.h"
ListNode *partition(ListNode *head, int x) {
    ListNode d1(-1), d2(-1);
    ListNode *small = &d1, *big = &d2, *curr = head;
    while(curr != nullptr) {
        if (curr->val < x) {
            small->next = curr;
            small = small->next;
            curr = curr->next;
            small->next = nullptr;
        } else {
            big->next = curr;
            big = big->next;
            curr = curr->next;
            big->next = nullptr;
        }
    }
    small->next = d2.next;
    return d1.next;
}
int main() {
    int A[] = {1, 4, 3, 2, 5, 2};
    ListNode *L = build(A, 1);
    L = partition(L, 7);
    print(L);
    return 0;
}
