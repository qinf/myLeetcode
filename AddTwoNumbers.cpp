#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) { }
};
ListNode *build(int A[], int n) {
    ListNode *L = nullptr, *p = nullptr;
    //ListNode *node = nullptr;
    for(int i = 0; i < n; ++i) {
        ListNode *node = new ListNode(A[i]);
        if (L == nullptr) {
            L = p = node;
        } else {
            p->next = node;
            p = p->next;
        }
    }
    return L;
}
void print(ListNode *L) {
    ListNode *p = L;
    while(p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *L = nullptr, *p = nullptr;
    int carry = 0;
    while(l1 != nullptr && l2 != nullptr) {
        int curr = l1->val + l2->val + carry;
        //cout << "curr: " << curr << endl;
        carry = curr/10;
        //cout << "carry: " << carry << endl;
        curr %= 10;
        ListNode *node = new ListNode(curr);
        if (nullptr == L) {
            L = p = node;
        } else {
            p->next = node;
            p = p->next;
        }
        //cout << curr << endl;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != nullptr) {
        int curr = carry + l1->val;
        carry = curr / 10;
        curr %= 10;
        ListNode *node = new ListNode(curr);
        if (nullptr == L) {
            L = p = node;
        } else {
            p->next = node;
            p = p->next;
        }
        l1 = l1->next;
    }
    while (l2 != nullptr) {
        int curr = carry + l2->val;
        carry = curr/10;
        curr %= 10;
        ListNode *node = new ListNode(curr);
        if (nullptr == L) {
            L = p = node;
        } else {
            p->next = node;
            p = p->next;
        }
        l2 = l2->next;
    }
    if (carry) {
        ListNode *node = new ListNode(carry);
        p->next = node;
        p = p->next;
        p->next = nullptr;
    }
    return L;
}
int main() {
    int A[] = {1};
    int B[] = {9, 9};
    ListNode *l1 = build(A, 1);
    print(l1);
    ListNode *l2 = build(B, 2);
    print(l2);
    ListNode *L = addTwoNumbers(l1, l2);
    print(L);
    return 0;
}
