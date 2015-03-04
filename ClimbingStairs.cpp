#include <iostream>
using namespace std;
int climbStairs(int n) {
    if (n <= 1)
        return n;
    else if (n == 2)
        return 2;
    int prev = 1, curr = 2;
    for (int i = 3; i <= n; ++i) {
        int tmp = curr;
        curr = curr + prev;
        prev = tmp;
    }
    return curr;
}
int main() {
    int ret = climbStairs(3);
    cout << ret << endl;
    return 0;
}
