/*
 * Given a sorted array of integers, find the starting and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */
#include <iostream>
#include <algorithm>
using std::next; using std::prev; using std::distance;
using std::vector;
using std::cout; using std::endl;

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

template<typename ForwardIterator, typename T>
ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, T value) {
    while (first != last) {
        auto mid = next(first, distance(first, last) / 2);
        if (value >= *mid)
            first = ++mid;
        else
            last = mid;
    }
    return first;
}

vector<int> searchRange(int A[], int n, int target) {
    auto lower = lower_bound(A, A+n, target);
    auto upper = upper_bound(A, A+n, target);
    if (lower == A + n || *lower != target)
        return vector<int> {-1, -1};
    return vector<int> {distance(A, lower), distance(A, prev(upper))};
}

int main() {
    int A[] = {5, 7, 7, 8, 8, 10};
    vector<int> vec = searchRange(A, 6, 8);
    for (auto a : vec)
        cout << a << " ";
    cout << endl;
    return 0;
}
