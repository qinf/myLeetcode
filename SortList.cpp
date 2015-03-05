#include "Struct.h"
#include <climits>
using std::cout; using std::endl;
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode dummy(-1);
    ListNode *p = &dummy;
    while (l1 != nullptr || l2 != nullptr) {
        int val1 = l1 == nullptr ? INT_MAX : l1->val;
        int val2 = l2 == nullptr ? INT_MAX : l2->val;
        if (val1 <= val2 && l1 != nullptr) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    return dummy.next;
}
ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    fast = head;
    while (fast->next != slow)
        fast = fast->next;
    fast->next = nullptr;
    fast = slow;
    slow = head;
    ListNode *l1 = sortList(slow);
    ListNode *l2 = sortList(fast);
    return mergeTwoLists(l1, l2);
}
int main() {
    int A[] = {1, 6, 3, 4, 2, 5};
    ListNode *L = build(A, 2);
    L = sortList(L);
    print(L);
    return 0;
}
