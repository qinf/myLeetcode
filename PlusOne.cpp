#include <iostream>
#include <vector>
using namespace std;
vector<int> plus_one(vector<int> &digits, int carry = 1) {
    auto rbeg = digits.rbegin();
    for(; rbeg != digits.rend(); ++rbeg) {
        *rbeg += carry;
        carry = *rbeg/10;
        *rbeg %= 10;
    }
    if (carry > 0) {
        digits.insert(digits.begin(), carry);
    }
    return digits;
}
vector<int> plusOne(vector<int> &digits) {
    vector<int> vec = plus_one(digits, 1);
    for(auto i : vec)
        cout << i << " ";
    cout << endl;
    return vec;
}

int main() {
    vector<int> digits = {9, 9, 9};
    plusOne(digits);
    return 0;
}
