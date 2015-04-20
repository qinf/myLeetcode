/*
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Determine if you are able to reach the last index.
 *
 * For example:
 * A = [2,3,1,1,4], return true.
 *
 * A = [3,2,1,0,4], return false.
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool canJump(vector<int> &nums) {
        const int N = nums.size();
        int reach = 1;
        for (int i = 0; i < reach && reach < N; i++) {
            reach = max(reach, i + 1 + nums[i]);
        }
        return reach >= N;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 1, 0, 4};
    cout << s.canJump(nums) << endl;
    return 0;
}
