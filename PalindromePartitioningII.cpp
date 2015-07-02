#include <iostream>
#include <string>
#include <algorithm>
using std::cout;
using std::endl;
using std::min;
using std::fill_n;
using std::string;

class Solution {
public:
    int minCut(string s) {
        const int n = s.size();
        int f[n+1];
        bool p[n][n];
        fill_n(&p[0][0], n * n, false);
        for (int i = 0; i <= n; i++)
            f[i] = n - i - 1;
        for (int i = n; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) {
                    p[i][j] = true;
                    f[i] = min(f[i], f[j+1] + 1);
                }
            }
        }
        return f[0];
    }
};

int main() {
    Solution sl;
    //string s = "abc";
    string s = "a";
    cout << sl.minCut(s) << endl;
    return 0;
}
