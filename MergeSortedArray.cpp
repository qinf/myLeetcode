#include <iostream>
using std::cout; using std::endl;
void merge(int A[], int m, int B[], int n) {
    int i = 0;
    int pos = m + n - 1;
    while(m > 0 && n > 0) {
        if (A[--m] > B[--n]) {
            A[pos - i] = A[m];
            ++n;
        } else {
            A[pos - i] = B[n];
            ++m;
        }
        ++i;
    }
    while (n > 0) {
        A[pos - i] = B[--n];
        ++i;
    }
}
int main() {
    int A[] = {4, 5, 6, 0, 0, 0};
    int B[] = {1, 2, 3};
    merge(A, 3, B, 3);
    for (int i = 0; i < 6; ++i)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}
