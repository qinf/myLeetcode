/* 如果有重复的话mid值=first值不能判断递增 *
 *
 */

#include <iostream>
using namespace std;
bool search(int A[], int n, int target) {
    int first = 0, last = n;
    while (first != last) {
        int mid = (first + last) >> 1;
        if (A[mid] == target) {
            return true;
        }
        if (A[first] < A[mid]) {
            if (A[first] <= target && target < A[mid]) {
                last = mid;
            } else {
                first = mid + 1;
            }
        } else if (A[first] > A[mid]) {
            if (A[mid] < target && target <= A[last - 1]) {
                first = mid + 1;
            } else {
                last = mid;
            }
        } else {
            ++first;
        }
    }
    return false;
}

int main() {
    int A[] = {1, 3, 1, 1};
    bool flag = search(A, 4, 2);
    cout << flag << endl;
    return 0;
}
