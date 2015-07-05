#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        const int m = word1.size();
        const int n = word2.size();
        // if (m == 0 || n == 0)
          //  return 0;
        int f[m+1][n+1];
        for (int i = 0; i <= m; ++i) {
            f[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            f[0][j] = j;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] = min(min(f[i][j - 1], f[i - 1][j - 1]), f[i - 1][j]) + 1;
                }
            }
        }
        return f[m][n];
    }
};

int main() {
    Solution s;
    string s1(""), s2("2");
    cout << s.minDistance(s1, s2) << endl;
    return 0;
}
