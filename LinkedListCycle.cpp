#include "Struct.h"
using namespace std;
bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}
int main() {
    int A[] = {1, 2};
    ListNode *L = build(A, 2);
    cout << hasCycle(L) <<endl;
    return 0;
}
