/*
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * For example:
 * Given array A = [2,3,1,1,4]
 *
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 *
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int> &nums) {
        const int N = nums.size();
        if (N == 1) return 0;
        int left = 0;
        int right = 0;
        int step = 0;
        while (left <= right) {
            ++step;
            const int old_right = right;
            for (int i = left; i <= old_right; ++i) {
                int new_right = i + nums[i];
                if (new_right >= N - 1)
                    return step;
                if (new_right > right)
                    right = new_right;
            }
            left = old_right + 1;
        }
        return 0;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 1};
    int n = s.jump(nums);
    cout << n << endl;
    return 0;
}
