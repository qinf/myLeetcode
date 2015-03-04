#include <iostream>
#include <vector>
using namespace std;
int singleNumber(int A[], int n) {
    int num = A[0];
    for (int i = 1; i < n; ++i)
        num ^= A[i];
    return num;
}

int main() {
    int A[] = {1, 2, 3, 3, 2, 1, 7};
    cout << singleNumber(A, 7) << endl;
    return 0;
}
