#include <iostream>
using namespace std;
int removeElement(int A[], int n, int elem) {
    //if (n == 0) return 0;
    int index = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i] != elem)
            A[index++] = A[i];
    }
    return index;
}
int main() {
    //int A[] = {1, 2, 3, 4, 5};
    int A[] = {};
    int ret = removeElement(A, 0, 3);
    for (auto i : A)
        cout << i << " ";
    cout << endl;
    cout << ret << endl;
    return 0;
}
