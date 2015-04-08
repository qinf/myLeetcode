/*
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 *
 */
#include <algorithm>
#include <iostream>
using std::next; using std::cout; using std::endl;
using std::distance; using std::prev;
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        auto lower = lower_bound(A, A + n, target);
        return distance(A, lower);
    }
private:
    template<typename ForwardIterator, typename T>
    ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, T value) {
        while (first != last) {
            auto mid = next(first, distance(first, last) / 2);
            if (value > *mid)
                first = ++mid;
            else
                last = mid;
        }
        return first;
    }
};

int main() {
    Solution solution;
    int A[] = {1, 3, 5, 6};
    //int A[] = {1};
    auto i = solution.searchInsert(A, 1, 0);
    cout << i << endl;
}
