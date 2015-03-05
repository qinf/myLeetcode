#include "Struct.h"
using namespace std;
ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr)
        return head;
    ListNode dummy(-1), *curr = head;
    ListNode *p = &dummy;
    while(curr != nullptr) {
        if (curr == head) {
            p->next = curr;
            p = p->next;
            curr = curr->next;
        } else {
            if (p->val == curr->val) {
                curr = curr->next;
                p->next = curr;
            } else {
                p->next = curr;
                p = p->next;
                curr = curr->next;
            }
        }
    }
    return dummy.next;
}
int main() {
    int A[] = {1, 1, 2, 3, 3};
    ListNode *L = build(A, 1);
    L = deleteDuplicates(L);
    print(L);
    return 0;
}
