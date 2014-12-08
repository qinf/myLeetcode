// Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author : Junzhong Qin
// Date : 2014-12-08

/**************************************************
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 * For example, the following two linked lists:
 *
 * A:          a1 → a2
 *                   ↘
 *                    c1 → c2 → c3
 *                   ↗
 * B:     b1 → b2 → b3
 * begin to intersect at node c1.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
**************************************************/
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
};
class {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            if (headA == NULL || headB == NULL)
                return NULL;
            int lengthA = 0, lengthB = 0;
            ListNode *pA = headA, *pB = headB;
            while(headA != NULL) {
                ++lengthA;
                headA = headA->next;
            }
            while(headB != NULL) {
                ++lengthB;
                headB = headB->next;
            }
            int length = lengthA > lengthB ? lengthB : lengthA;
            while(lengthA - lengthB > 0) {
                pA = pA->next;
                --lengthA;
            }
            while(lengthB - lengthA > 0) {
                pB = pB->next;
                --lengthB;
            }
            for (int i = 0; i < length; ++i) {
                if (pA == pB)
                    return pA;
                else {
                    pA = pA->next;
                    pB = pB->next;
                }
            }
            return NULL;
        }
};
