#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        add(digits, 1);
        return digits;
    }
private:
// 0 <= digit <= 9
void add(vector<int> &digits, int digit) {
    int carry = digit;
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        *it += carry;
        carry = *it / 10;
        *it %= 10;
    }
    if (carry > 0)
        digits.insert(digits.begin(), 1);
    }
};
int main() {
    vector<int> digits = {1, 2, 3};
    Solution s;
    s.plusOne(digits);
    for (auto i : digits)
        cout << i << " ";
    cout << endl;
}
