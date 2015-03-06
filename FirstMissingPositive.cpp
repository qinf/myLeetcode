//思想： 遍历数组，只要A[i] != i+1，则循环交换A[i]和A[A[i]-1]
#include <iostream>
using std::cout; using std::endl;
void bucket_sort(int A[], int n) {
    for (int i = 0; i < n; ++i) {
        while (A[i] != i + 1) {
            if (A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1]) {
                break;
            } else {
                std::swap(A[i], A[A[i] - 1]);
            }
        }
    }
}
int firstMissingPositive(int A[], int n) {
    bucket_sort(A, n);
    for (int i = 0; i < n; i++) {
        if (A[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}

int main() {
    int A[] = {3, 4, -1, 1};
    int ret = firstMissingPositive(A, 4);
    cout << ret << endl;
    return 0;
}
