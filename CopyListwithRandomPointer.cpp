#include "Struct.h"
#include <iostream>
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x): label(x), next(nullptr), random(nullptr) { }
};
RandomListNode *copyRandomList(RandomListNode *head) {
    if (head == nullptr) {
        return head;
    }
    cout << "1111111111111" << endl;
    RandomListNode *origin = head;
    while (origin != nullptr) {
        RandomListNode *node = new RandomListNode(origin->label);
        node->next = origin->next;
        origin->next = node;
        origin = node->next;
    }
    cout << "2111111111111" << endl;
    origin = head;
    while (origin != nullptr) {
        if (origin->random != nullptr) {
            origin->next->random = origin->random->next;
        }
        origin = origin->next->next;
    }
    cout << "3111111111111" << endl;
    origin = head;
    RandomListNode *newList = head->next;
    RandomListNode *retList = newList;
    while (origin != nullptr) {
        origin->next = newList->next;
        origin = origin->next;
        if (newList->next != nullptr) {
            newList->next = newList->next->next;
            newList = newList->next;
        }
    }
    cout << "4111111111111" << endl;
    return retList;
};
int main() {
    RandomListNode *head = new RandomListNode(1);
    RandomListNode *head2 = new RandomListNode(2);
    RandomListNode *head3 = new RandomListNode(3);
    head->next = head2;
    head2->next = head3;
    RandomListNode *ret = copyRandomList(head);
    return 0;
}
