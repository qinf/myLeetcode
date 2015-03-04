#include "Struct.h"
using namespace std;
ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}
int main() {
    int A[] = {1, 2, 3};
    ListNode *L = build(A, 3);
    L->next->next->next = L->next;
    ListNode *p = detectCycle(L);
    cout << p->val << endl;
    return 0;
}
