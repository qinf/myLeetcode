#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = grid.size();
        if (m == 0)
            return 0;
        const int n = grid[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0));
        f[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            f[i][0] = grid[i][0] + f[i - 1][0];
        }
        for (int j = 1; j < n; ++j) {
            f[0][j] = grid[0][j] + f[0][j - 1];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] = min(f[i][j - 1], f[i - 1][j]) + grid[i][j];
            }
        }
        return f[m - 1][n - 1];
    }

    int minPathSum2(vector<vector<int> > & grid) {
        const int m = grid.size();
        if (m == 0)
            return 0;
        const int n = grid[0].size();
        int f[n];
        fill(f, f + n, INT_MAX);
        f[0] = 0;

        for(int i = 0; i < m; ++i) {
            f[0] += grid[i][0];
            for (int j = 1; j < n; ++j) {
                f[j] = min(f[j - 1], f[j]) + grid[i][j];
            }
        }
        return f[n - 1];
    }
};

int main() {
    Solution s;
    vector<vector<int> > grid = {{1, 2}, {3, 1}};
    cout << s.minPathSum2(grid) << endl;
    return 0;
}
