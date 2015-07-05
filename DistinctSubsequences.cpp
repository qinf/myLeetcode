#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        const int m = s.size();
        const int n = t.size();
        if (m == 0)
            return 0;
        else if (n == 0)
            return 1;
        int f[m + 1][n + 1];
        f[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            f[i][0] = 1;
        }
        for (int j = 1; j <= n; ++j) {
            f[0][j] = 0;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i - 1][j];
                }
            }
        }
        return f[m][n];
    }
};

int main() {
    Solution solution;
    string s("b"), t("a");
    cout << solution.numDistinct(s, t) << endl;
    return 0;
}
