/* tips:
 *       /
 *     / |
 *   /   |
 * /     |
 *       |   /
 *       | /
 *       /
 */
#include <iostream>
using namespace std;
int search(int A[], int n, int target) {
    int first = 0, last = n;
    while (first != last) {
        int mid = (first + last) >> 1;
        if (A[mid] == target)
            return mid;
        if (A[first] <= A[mid]) {
            if (A[first] <= target && target < A[mid]) {
                last = mid;
            } else {
                first = mid + 1;
            }
        } else {
            if (A[mid] < target && target <= A[last - 1]) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }
    }
    return -1;
}

int main() {
    int A[] = {4, 5, 6, 7, 0, 1, 2};
    int index = search(A, 7, 4);
    cout << index << endl;
    return 0;
}
