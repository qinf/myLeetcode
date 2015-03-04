#include <iostream>
using namespace std;
int removeDuplicates(int A[], int n) {
    if(n <= 2) return n;
    int count = 0, index = 0;
    for(int i = 1; i < n; ++i) {
        if(A[index] != A[i]) {
            A[++index] = A[i];
            count = 0;
        } else if(++count == 1) {
            A[++index] = A[i];
        }
    }
    return index + 1;
}

int main(int argc, char** argv) {
    int A[] = {1,1,1,2,2,2,2,3,3};
    int len = removeDuplicates(A, 9);
    cout << len << endl;
    return 0;
}
