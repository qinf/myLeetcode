#include "Struct.h"
#include <vector>
#include <climits>
using std::vector;
using std::endl; using std::cout;
ListNode *mergeTwoLists(ListNode *p1, ListNode *p2) {
    ListNode dummy(-1);
    /*
    for (ListNode* p = &dummy; p1 != nullptr || p2 != nullptr; p = p->next) {
        int val1 = p1 == nullptr ? INT_MAX : p1->val;
        int val2 = p2 == nullptr ? INT_MAX : p2->val;
        if (val1 < val2) {
            p->next = p1;
            p1 = p1->next;
        } else {
            p->next = p2;
            p2 = p2->next;
        }
    }
    */
    ListNode *head = &dummy;
    while(p1 != nullptr && p2 != nullptr) {
        if (p1->val < p2->val) {
            head->next = p1;
            head = head->next;
            p1 = p1->next;
        } else {
            head->next = p2;
            head = head->next;
            p2 = p2->next;
        }
    }
    if (p1 != nullptr) {
        head->next = p1;
    }
    if (p2 != nullptr) {
        head->next = p2;
    }
    //head->next = nullptr;
    return dummy.next;
}
ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0) return nullptr;
    if (lists.size() == 1) return lists[0];
    ListNode *p1, *p2, *p;
    while (lists.size() > 1) {
        p1 = lists.back();
        lists.pop_back();
        p2 = lists.back();
        lists.pop_back();
        p = mergeTwoLists(p1, p2);
        lists.insert(lists.begin(), p);
    }
    return lists[0];
}
int main() {
    int A[] = {1, 3, 4};
    int B[] = {2, 3, 5};
    int C[] = {2, 3, 4};
    ListNode *p1 = build(A, 3);
    ListNode *p2 = build(B, 3);
    ListNode *p3 = build(C, 3);
    //p1 = mergeTwoLists(p1, p2);
    vector<ListNode *> vec = {p1, p2, p3};
    p1 = mergeKLists(vec);
    print(p1);
    return 0;
}
