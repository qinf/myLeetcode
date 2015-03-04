#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>
using namespace std;
int threeSumClosest(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    int dis = INT_MAX;
    int sum = 0, old_sum = 0;
    const int n = num.size();
    for (int i = 0; i < n - 2; ++i) {
        int a = num[i];
        int left = i + 1;
        int right = n -1;
        while (left < right) {
            int sum = a + num[left] + num[right];
            int gap = abs(sum - target);
            if (gap < dis) {
                old_sum = sum;
                dis = gap;
            }
            if (sum < target)
                ++left;
            else
                --right;
        }
    }
    return old_sum;
}

int main() {
    vector<int> num = {1,2,4,8,16,32,64,128};
    int ret = threeSumClosest(num, 82);
    cout << ret << endl;
    return 0;
}
