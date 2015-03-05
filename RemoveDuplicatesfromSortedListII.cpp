#include "Struct.h"
using namespace std;
ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr)
        return nullptr;
    //int i = (head->val != INT_MAX) ? INT_MAX : INT_MAX + 1;
    ListNode dummy(-1);
    ListNode *prev = &dummy, *curr = head;
    //dummy.next = head;
    while(curr != nullptr) {
        bool duplicate = false;
        while(curr->next && curr->val == curr->next->val) {
            duplicate = true;
            ListNode *tmp = curr;
            curr = curr->next;
            delete tmp;
        }
        if (duplicate) {
            ListNode *tmp = curr;
            curr = curr->next;
            delete tmp;
            continue;
        }
        prev->next = curr;
        prev = prev->next;
        curr = curr->next;
    }
    prev->next = nullptr;
    return dummy.next;
}
int main() {
    int A[] = {1, 2, 3, 3, 4, 4, 5};
    ListNode *L = build(A, 4);
    L = deleteDuplicates(L);
    print(L);
    return 0;
}
