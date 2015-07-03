/*
 *  f[i][j] represent the state of s1[0,i) and s2[0, j)
 *  f[i][j] = (s1[i-1] == s3[i + j - 1] && f[i - 1][j]) ||
 *              (s2[j-1] == s3[i+j-1] && f[i][j-1])
 *
 *  动态规划要有初始状态:
 *  f[i][0], f[0][j]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int n1 = s1.size();
        const int n2 = s2.size();
        const int n3 = s3.size();
        if (n1 + n2 != n3)
            return false;

        vector<vector<bool>> f(n1 + 1, vector<bool>(n2 + 1, true));
        for (int i = 1; i <= s1.size(); i++) {
            f[i][0] = (s1[i-1] == s3[i-1] && f[i - 1][0]);
        }
        for (int i = 1; i <= s2.size(); i++) {
            f[0][i] = (s2[i-1] == s3[i-1] && f[0][i-1]);
        }

        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                f[i][j] = (s1[i - 1] == s3[i + j - 1] && f[i - 1][j])
                    || (s2[j - 1] == s3[i + j - 1] && f[i][j - 1]);
            }
        }
        return f[n1][n2];
    }
};


int main() {
    Solution s;
    string s1("aabcc"), s2("dbbca"), s3("aadbbcbcac");
    cout << s.isInterleave(s1, s2, s3) << endl;
    return 0;
}
