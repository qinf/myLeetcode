#include <iostream>
using std::cout; using std::endl;
void sortColors(int A[], int n) {
    int counts[3] = {0};
    for (int i = 0; i < n; ++i) {
        if (A[i] == 0) {
            ++counts[0];
        } else if (A[i] == 1) {
            ++counts[1];
        } else {
            ++counts[2];
        }
    }
    int i = 0;
    while (counts[0]--)
        A[i++] = 0;
    while (counts[1]--)
        A[i++] = 1;
    while (counts[2]--)
        A[i++] = 2;
}
int main() {
    int A[] = {0, 1, 2, 0, 2, 1, 0};
    sortColors(A, 7);
    for(int i = 0; i < 7; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}
