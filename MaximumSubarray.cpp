#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (sum < 0) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }
            if (sum > ret)
                ret = sum;
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(vec) << endl;
    return 0;
}
