/*
 * Implement int sqrt(int x).
 * Compute and return the square root of x.
 *
 */
#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int left = 1, right = x >> 1;
        int mid;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (x / mid > mid) {
                left = mid + 1;
                mid = left + ((right - left) >> 1);
            } else if (x / mid < mid) {
                right = mid - 1;
                mid = left + ((right - left) >> 1);
            } else {
                return mid;
            }
        }
        return mid;
    }
};

int main() {
    Solution s;
    int ret = s.mySqrt(2);
    cout << ret << endl;
    return 0;
}
