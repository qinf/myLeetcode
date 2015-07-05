#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings2(string s) {
        if (s.size() == 0 || s[0] == '0')
            return 0;
        vector<int> dp(s.size(), 0);
        dp[0] = 1;
        for (int i = 1; i < s.size(); ++i) {
            bool one = true, two = true;
            if (s[i - 1] == '0' || s[i - 1] > '2' || (s[i - 1] == '2' && s[i] > '6')) {
                two = false;
            }
            if (s[i] == '0') {
                one = false;
            }
            if (two && one) {
                dp[i] = (i == 1 ? 2 : dp[i - 1] + dp[i - 2]);
            }
            if (two && !one) {
                dp[i] = (i == 1 ? 1 :dp[i - 2]);
            }
            if (!two && one) {
                dp[i] = dp[i - 1];
            }
            if (!two && !one) {
                dp[i] = 0;
            }
        }
        return dp[s.size() - 1];
    }
};

int main() {
    Solution s;
    vector<string> vec;
    vec.push_back("");
    vec.push_back("100");
    vec.push_back("01");
    vec.push_back("10");
    vec.push_back("110");
    vec.push_back("1224");
    for (auto str : vec) {
        cout << s.numDecodings2(str) << endl;
    }
    return 0;
}
