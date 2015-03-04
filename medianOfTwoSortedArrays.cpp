#include <iostream>
using namespace std;
double find_kth(int A[], int m, int B[], int n, int k);
double medianOfArrays(int A[], int m, int B[], int n) {
    int total = m + n;
    if (total & 0x1)
        return find_kth(A, m, B, n, (total / 2) + 1);
    else
        return (find_kth(A, m, B, n, total / 2) + find_kth(A, m, B, n, (total / 2) + 1)) / 2;
}

double find_kth(int A[], int m, int B[], int n, int k) {
    if (m > n) {
        return find_kth(B, n, A, m, k);
    }
    if (0 == m) return B[k - 1];
    if (1 == k) return A[0] > B[0] ? B[0] : A[0];

    // divide k into two parts
    int pa = k/2 > m ? m : k/2, pb = k - pa;
    if (A[pa - 1] < B[pb - 1])
        return find_kth(A + pa, m - pa, B, n, k - pa);
    else if (A[pa - 1] > B[pb - 1])
        return find_kth(A, m, B + pb, n - pb, k - pb);
    else
        return A[pa - 1];
}

int main() {
    int A[] = {1, 2, 3, 5, 6};
    int B[] = {4};
    double ret = medianOfArrays(A, 5, B, 1);
    cout << ret << endl;
    return 0;
}
