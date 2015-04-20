/*
 * Implement pow(x, n).
 *
 */
#include <iostream>
using namespace std;
class Solution {
public:
    double pow(double x, int n) {
        if (n < 0) return 1.0 / power(x, -n);
        else
            return power(x, n);
    }
private:
    double power(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        double v = pow(x, n >> 1);
        if (n % 2)
            return x * v * v;
        else
            return v * v;
    }
};

int main() {
    Solution s;
    double ret = s.pow(8.84372, -5);
    cout << ret << endl;
    return 0;
}
