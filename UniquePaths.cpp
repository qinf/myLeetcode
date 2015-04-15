/*
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * How many possible unique paths are there?
 *
 *
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 *
 */
#include <iostream>
#include <vector>
using std::cout; using std::endl;
using std::vector;

// 超时
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1) return 0;
        if (m == 1 && n == 1) return 1;
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};
class Solution2 {
public:
    int uniquePaths(int m, int n) {
        this->f = vector<vector<int>>(m + 1, vector<int>(n+1, 0));
        return dfs(m, n);
    }
private:
    vector<vector<int>> f;
    int dfs(int x, int y) {
        if (x < 1 || y < 1) return 0;
        if (x == 1 && y == 1) return 1;
        return getOrUpdate(x - 1, y) + getOrUpdate(x, y - 1);
    }
    int getOrUpdate(int x, int y) {
        if (f[x][y] > 0) return f[x][y];
        else return f[x][y] = dfs(x, y);
    }
};

int main() {
    Solution2 s;
    cout << s.uniquePaths(3, 4) << endl;
    return 0;
}
