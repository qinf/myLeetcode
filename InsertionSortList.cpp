#include "Struct.h"
using std::cout; using std::endl;
ListNode *findFirsthInsertPos(ListNode *p, int val) {
    ListNode *ptr = p;
    while (ptr->next && ptr->next->val < val) {
        ptr = ptr->next;
    }
    return ptr;
}
ListNode *insertionSortList(ListNode *head) {
    ListNode dummy(-1);
    ListNode *L = &dummy;
    while (head != nullptr) {
        ListNode *pos = findFirsthInsertPos(L, head->val);
        ListNode *curr = head->next;
        head->next = pos->next;
        pos->next = head;
        head = curr;
    }
    return dummy.next;
}
int main() {
    int A[] = {2, 2, 2, 2};
    ListNode *L = build(A, 4);
    L = insertionSortList(L);
    print(L);
    return 0;
}
