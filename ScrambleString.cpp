//  三维动态规划
//  对s1和s2进行划分，长度为k，则有：
//      s1a和s2a、s1b和s2b互为Scramble string
//      或者 s1a和s2b、s1b和s2a互为scramble string
//  f[N][i][j] = (f[k][i][j] && f[n - k][i + k][i + k])
//              || (f[k][i][n -k + j] && f[n - k][k + i][j])
//  初始状态?
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        const int N = s1.size();
        if (N != s2.size())
            return false;
        bool f[N + 1][N][N];
        fill_n(&f[0][0][0], (N + 1) * N * N, false);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                f[1][i][j] = s1[i] == s2[j];
            }
        }

        for (int n = 1; n <= N; ++n) {
            for (int i = 0; i + n <= N; ++i) {
                for (int j = 0; j + n <= N; ++j) {
                    for (int k = 1; k < n; ++k) {
                        if ((f[k][i][j] && f[n - k][k + i][k + j])
                                         || (f[k][i][n - k +j] && f[n - k][k + i][j])) {
                            f[n][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return f[N][0][0];
    }
};

int main() {
    Solution s;
    // string s1("rgeat"), s2("graet");
    string s1("abb"), s2("bba");
    cout << s.isScramble(s1, s2) << endl;
    return 0;
}
